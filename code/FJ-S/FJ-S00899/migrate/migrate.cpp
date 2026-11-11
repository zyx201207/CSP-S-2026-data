#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long int64;
const int LL = 2e5, Mod = 1e9 + 7;
int C, T, N;
int64 D, Ans, a[LL + 5];
inline int64 read()
{
	int64 k = 0, f = 1;
	char t = getchar();
	while(t < '0' || t > '9')
	{
		if(t == '-')
			f = -1ll;
		t = getchar();
	}
	while(t >= '0' && t <= '9')
	{
		k = k * 10ll + t - '0';
		t = getchar();
	}
	return k * f;
}

int main()
{
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	C = read(), T = read();
	while(T--)
	{
		Ans = 0;
		N = read(), D = read();
		for(int i = 1; i <= N; i++)
			a[i] = read();
		int pos = 0;
		for(int i = 1; i <= N; i++)
		{
			if(a[i] - a[1] <= D)
				pos = i;
			else
				break;
		}
		Ans = N - (2ll * pos - 1ll) + 2ll;
		printf("%lld\n", Ans);
	}
	return 0;
}
