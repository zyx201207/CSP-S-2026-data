#include <cstdint>
#include <iostream>
#include <cmath>

using namespace std;

int64_t Island[2097152];
uint64_t Short[2097152];
uint64_t ShortCount[2097152];

int main()
{
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);

	uint64_t C, T;
	uint64_t N, D;
	uint64_t Result;
	uint64_t CurrentShort, CurrentShortCount;
	bool ShouldBreak;

	cin >> C >> T;

	for (uint64_t K = 0; K < T; ++K)
	{
		Result = 0;
		cin >> N >> D;
		for (uint64_t I = 0; I < N; ++I)
		{
			cin >> Island[I];
		}

		if (C == 11 || C == 12)
		{
			if (N < 2)
			{
				cout << 0 << endl;
				continue;
			}

			// 公差.
			uint64_t M = Island[1] - Island[0];

			// 跳跃数量.
			uint64_t MNumber = D / M;

			for (uint64_t From = 0; From < N; ++From)
			{
				if (N - From > MNumber * 2)
				{
					Result = MNumber;
				}
				else
				{
					Result = max((int64_t)(N - From) - (int64_t)(MNumber + 1), 0LL);
				}
			}
		}
		else
		{
			// 固定一个 From, 获取最短路径数.
			for (uint64_t From = 0; From < N; ++From)
			{
				// 初始化.
				for (int64_t I = From - 1; I >= 0 && Island[From] - Island[I] <= D; ++I)
				{
					Short[I] = UINT64_MAX;
					ShortCount[I] = 0;
				}

				Short[From] = 0;
				ShortCount[From] = 1;

				// 对全部路径进行扫描.
				for (uint64_t To = From + 1; To < N; ++To)
				{
					CurrentShort = UINT64_MAX;
					CurrentShortCount = 0;

					ShouldBreak = true;

					// 遍历得到最短路径及其数量.
					for (int64_t J = To - 1; J >= 0 && Island[To] - Island[J] <= D; --J)
					{
						if (ShortCount[J] != 0)
						{
							ShouldBreak = false;
						}

						if (Short[J] < CurrentShort)
						{
							CurrentShort = Short[J];
							CurrentShortCount = ShortCount[J];
						}
						else if (Short[J] == CurrentShort)
						{
							CurrentShortCount += ShortCount[J];
						}
					}

					if (ShouldBreak)
					{
						break;
					}

					Short[To] = CurrentShort + 1;
					ShortCount[To] = CurrentShortCount;

					// 找到双径岛屿对.
					if (ShortCount[To] == 2)
					{
						++Result;
					}
				}
			}
		}

		cout << Result << endl;
	}

	fclose(stdin);
	fclose(stdout);

	return 0;
}
