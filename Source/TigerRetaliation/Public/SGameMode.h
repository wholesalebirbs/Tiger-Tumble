// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "SGameMode.generated.h"

enum class EWaveState : uint8;

DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams (FOnActorKilled, AActor*, VictimActor, AActor*, KillerActor, AController*, KillerController); //Killed actoor, killer actor

/**
 * 
 */
UCLASS()
class TIGERRETALIATION_API ASGameMode : public AGameModeBase
{
	GENERATED_BODY()
	
protected:

	FTimerHandle TimerHandle_BotSpawner;

	FTimerHandle TimerHandle_NextWaveStart;

	//bots to spawn in currents wave
	int32 NrOfBotsToSpawn;

	int32 WaveCount;

	UPROPERTY(EditDefaultsOnly, Category = "GameMode")
	float TimeBetweenWaves;

	//hook for bp to spawn a single bot
	UFUNCTION(BlueprintImplementableEvent, Category = "GameMode")
	void SpawnNewBot();


	void SpawnBotTimerElapsed();
	
	//start spawning bots
	void StartWave();


	//stopspawningbots
	void EndWave();

	//settimer for next startwave
	void PrepareForNextWave();

	void CheckWaveState();

	void CheckAnyPlayerAlive();

	void GameOver();

	void SetWaveState(EWaveState NewState);


	void RestartDeadPlayers();

public:

	ASGameMode();

	virtual void StartPlay() override;

	virtual void Tick(float DeltaSeconds) override;

	UPROPERTY(BlueprintAssignable, Category = "GameMode")
	FOnActorKilled OnActorKilled;
};
