#include <cstdint>
#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

int64_t A[524288];

int main()
{
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	
	uint64_t N, M, Result;
	uint64_t Lower, Upper, LowerDelta, UpperDelta, CurrentM, CurrentResult;
	
	Result = 0;
	
	cin >> N >> M;
	for (uint64_t K = 0; K < N; ++K)
	{
		cin >> A[K];
	}
	
	sort(A, A + N);
	
	for (uint64_t I = 0; I < N; ++I)
	{
		Lower = I;
		Upper = I;
		CurrentM = 0;

		while (true)
		{
			// 计算差分. 
			if (Lower != 0)
			{
				if (Upper != N - 1)
				{
					LowerDelta = A[I] - A[Lower - 1];
					UpperDelta = A[Upper + 1] - A[I];
				}
				else
				{
					LowerDelta = A[I] - A[Lower - 1];
					UpperDelta = UINT64_MAX;
				}
			}
			else
			{
				if (Upper != N - 1)
				{
					LowerDelta = UINT64_MAX;
					UpperDelta = A[Upper + 1] - A[I];
				}
				else
				{
					Result = N;
					
					goto RESULT;
				}
			}
			
			// 判断是否超出要求. 
			if ((CurrentM + min(LowerDelta, UpperDelta)) <= M)
			{
				if (LowerDelta < UpperDelta)
				{
					--Lower;
					CurrentM += LowerDelta;
				}
				else
				{
					++Upper;
					CurrentM += UpperDelta;
				}
			}
			else
			{
				CurrentResult = Upper - Lower + 1;
				break;
			}
		}
		
		Result = max(Result, CurrentResult);
	}

RESULT:
	cout << Result;

	fclose(stdin);
	fclose(stdout);

	return 0;
}

