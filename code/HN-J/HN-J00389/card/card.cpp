#include<bits/stdc++.h>
#define int long long
using namespace std;
typedef long long ll;
const int N = 5e5 + 10, M = 3e5 + 10;
int n, m, a[N], ans[M], f[N], mp[M];
//map<int, int> mp;
signed main()
{
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1; i <= n; i ++) cin >> a[i];
	for(int i = 1; i <= n; i ++)
	{
		memset(mp, 0, sizeof mp);
		memset(f, 0, sizeof f);
		int k = 0;
		for(int j = i; j <= n; j ++)
		{
			if(!mp[a[j]])
			{
				f[++ k] = a[j];
				mp[a[j]] = k;
			}else{
				for(int x = mp[a[j]] + 1; x <= k; x ++)
				{
					mp[f[x]] = 0;
				}
				k = mp[a[j]];
			}
		}
		for(int i = 1; i <= k; i ++) ans[f[i]] ++;
	}
	for(int i = 1; i <= m; i ++) cout << ans[i] << " ";
	return 0;
}

