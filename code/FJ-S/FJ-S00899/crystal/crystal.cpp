#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long int64;
const int LL = 5e5, Mod = 1e9 + 7;
int64 N, M, Ans = 1, a[LL + 5], d[LL + 5], s[LL + 5];
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
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	N = read(), M = read();
	for(int i = 1; i <= N; i++)
		a[i] = read();
	sort(a + 1, a + 1 + N);
	for(int i = 1; i <= N; i++)
		d[i - 1] = a[i] - a[i - 1];
	int64 sum = a[1];
	for(int64 i = 1, j = 1; i < N; i++)
	{
		sum -= a[j] - a[i - 1];
		while(j < N && sum + (j - i + 1)*d[j] <= M)
			sum += (j - i + 1) * d[j], j++;
		Ans = max(Ans, j - i + 1);
	}
	printf("%lld", Ans);
	return 0;
}
