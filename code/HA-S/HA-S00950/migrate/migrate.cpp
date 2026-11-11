#include <bits/stdc++.h>

using namespace std;

#define int long long

const int N = 2000010;

int n, k;
int x[N];
namespace From_1_to_2
{
	int cnt[15][15], Min[15][15];
	inline void solve ()
	{
		scanf("%lld %lld", &n, &k);
		for (int i = 1; i <= n; i++) scanf("%lld", &x[i]);
		memset(cnt, 0, sizeof cnt);
		memset(Min, 63, sizeof Min);
		
		for (int i = 0; i < (1 << n); i++)
		{
			vector <int> vec;
			for (int j = 0; j < n; j++)
				if ((i >> j) & 1)
					vec.push_back(j + 1);
			
			int flg = 1;
			for (int j = 1; j < vec.size(); j++)
				if (x[vec[j]] - x[vec[j - 1]] > k)
					flg = 0;
			
			if (flg && vec.size() >= 2)
			{
				int st = vec[0], ed = vec[vec.size() - 1], len = vec.size() - 1;
//				printf("%lld %lld %lld\n", st, ed, len);
				if (Min[st][ed] == len) cnt[st][ed]++;
				else if (Min[st][ed] > len) Min[st][ed] = len, cnt[st][ed] = 1;
			}
		}
		
		int Ans = 0;
		for (int l = 1; l <= n; l++)
			for (int r = l; r <= n; r++)
				Ans += (cnt[l][r] == 2);
		printf("%lld\n", Ans);
	}
}

namespace From_11_to_12
{
	inline void solve ()
	{
		scanf("%lld %lld", &n, &k);
		for (int i = 1; i <= n; i++) scanf("%lld", &x[i]);
		
		
	}
}

namespace From_15_to_18
{
	inline void solve ()
	{
		scanf("%lld %lld", &n, &k);
		for (int i = 1; i <= n; i++) scanf("%lld", &x[i]);
		
	}
}

int c, T;
signed main ()
{
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	scanf("%lld %lld", &c, &T);
	if (0 <= c && c <= 2) while (T--) From_1_to_2::solve();
	if (11 <= c && c <= 12) while (T--) From_11_to_12::solve();
	if (15 <= c && c <= 18) while (T--) From_11_to_12::solve();
	return 0;
}
// Only feels like nothing could be better when I with you, when I with you ~ 
// Dancing all night pray we're next together it's a breakthough, it's a breakthough ~
