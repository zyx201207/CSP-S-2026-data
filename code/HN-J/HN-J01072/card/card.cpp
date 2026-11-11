#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 5e5 + 10,INF = 0x3f3f3f3f3f3f3f3f;
int n,m,a[N],ans[N],fir[N],cnt[N],maxn,l = 1;
bool vis[N];
signed main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
		cnt[a[i]]++;
		maxn = max(cnt[a[i]],maxn);
	}
	while (l <= n)
	{
		memset(fir,0x3f,sizeof(fir));
		memset(vis,0,sizeof(vis));
		for (int i = l; i <= n; i++)
		{
			if (vis[a[i]])
			{
				for (int j = fir[a[i]]; j < i; j++)
				{
					vis[a[j]] = 0;
					fir[a[j]] = INF;
				}
				fir[a[i]] = i;
			}
			vis[a[i]] = 1;
			fir[a[i]] = min(fir[a[i]],i);
		}
		for (int i = 1; i <= m; i++)
		{
			ans[i] += vis[i];
			vis[i] = 0;
		}
		l++;
	}
	for (int i = 1; i <= m; i++)
	{
		cout << ans[i] << ' ';
	}
	return 0;
}

