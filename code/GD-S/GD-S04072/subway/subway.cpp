#include<bits/stdc++.h>
using namespace std;
const long long N = 510;
const long long M = 2e4 + 10;
struct ed{long long x,t;};
ed a[N][M];
long long C,n,m,d,q,w[M],k[N],b[N][M];
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>C>>n>>m>>d>>q;
	for(int i = 1 ; i <= m ; i ++) cin>>w[i];
	for(int i = 1 ; i <= n ; i ++)
	{
		cin>>k[i];
		for(int j = 1 ; j <= k[i] ; j ++) cin>>a[i][j].x>>a[i][j].t;
	}
	for(int p = 1 ; p <= q ; p ++)
	{
		long long u,v,cnt = 0,ans = 0;
		cin>>u>>v;
		if(u > v) swap(u,v);
		ans += w[u];
		ans += w[v];
		for(int i = u ; i <= n ; i ++)
		{
			for(int j = 1 ; j <= m ; j ++)
			{
				ans += a[i][j].t;
				if(a[i][j].x == v)
				{
					cnt = -1;
					break;
				}
				if(cnt == -1) break;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
