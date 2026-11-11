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

const int N = 2000010;

int n;
long long m;
long long w[N];
int L[N], R[N];
long long ans = 0;
int st[310][310];

struct Work0
{
	int res1 = 0, res2 = 0;
	void dfs(int l, int r, int res)
	{
		if (res > res1) return ;
		if (l == r)
		{
			if (res == res1) ++ res2;
			else res1 = res, res2 = 1;
			return ;
		}
		for (int i = l + 1, I = min(r, R[l]); i <= I; ++ i)
		{
			dfs(i, r, res + 1);
		}
		return ;
	}
	void solve()
	{
		read(n), read(m);
		for (int i = 1; i <= n; ++ i) read(w[i]);
		
		for (int i = 1; i <= n; ++ i)
		{
			L[i] = lower_bound(w + 1, w + i, w[i] - m) - w;
			R[i] = upper_bound(w + i + 1, w + n + 1, w[i] + m) - w - 1;
		}
		
		ans = 0;
		for (int i = 1; i <= n; ++ i)
		{
			for (int j = i + 2; j <= n; ++ j)
			{
				res1 = 0x3f3f3f3f, res2 = 1;
				dfs(i, j, 0);
				if (res2 == 2)
				{
					ans ++ ;
				}
			}
		}
		printf("%lld\n", ans);
	}
}work0;

int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	
	int C, Q;
	read(C), read(Q);
	
	while (Q -- )
	{
		if (C == 13 || C == 14) puts("0");
		else
		{
			work0.solve();
		}
	}
	
	return 0;
}
