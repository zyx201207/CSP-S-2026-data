#include <iostream>
#include <algorithm>

using namespace std;

template <typename T>
inline void read(T &Fw)
{
	static char Fc;
	static int Fop;
	Fop = 1;
	Fw = 0;
	do {Fc = getchar();}while ((Fc < '0' || Fc > '9') && Fc != '-');
	if (Fc == '-') Fc = getchar(), Fop = -1;
	do {Fw = (Fw << 1) + (Fw << 3) + (Fc ^ 48), Fc = getchar();}while (Fc >= '0' && Fc <= '9');
	Fw *= Fop;
}

const int N = 500010;

int n;
long long m, w[N], sum[N];

void solve()
{
	read(n), read(m);
	for (int i = 1; i <= n; ++ i) read(w[i]);
	sort (w + 1, w + n + 1);
	for (int i = 1; i <= n; ++ i) sum[i] = sum[i - 1] + w[i];
	
	int ans = 1;
	for (int u = 2; u <= n; ++ u)
	{
		int l = 1, r = u;
		while (l < r)
		{
			int mid = l + r + 1 >> 1;
			if (w[u] * mid - (sum[u] - sum[u - mid]) <= m) l = mid;
			else r = mid - 1;
		}
		ans = max(ans, r);
	}
	printf("%d\n", ans);
}

int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	solve();
	return 0;
}
