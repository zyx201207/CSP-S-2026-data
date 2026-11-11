#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll n, m, a[500007], cnt[300007], ans[300007];
int main()
{
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	
	scanf("%lld%lld", &n, &m);
	for(ll i = 1; i <= n; i ++)
	{
		scanf("%lld", &a[i]);
	}
	for(ll i = 1; i <= n; i ++)
	{
		bool flag = 0;
		if (cnt[a[i]]) 
		{
			for(ll j = 1; j <= i - 1; j ++)
			{
				if(cnt[j] == a[i] || flag) 
				{
					a[i] = -1;
					cnt[a[i]] --;
					flag = 1;
				}
			}
		}
		cnt[a[i]] ++;
		for(ll j = 1; j <= m; j ++) if (cnt[a[j]] && a[j] != -1 && a[j] != a[i]) ans[a[j]] ++;
	}
	for(ll i = 1; i <= m; i ++) printf("%lld ", ans[i] - 1);
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
