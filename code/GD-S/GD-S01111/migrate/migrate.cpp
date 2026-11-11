#include<bits/stdc++.h>
using namespace std;
#define int long long
int c,t,n,d,x[2000005],ans;
void solve()
{
	cin>>n>>d;ans=0;
	for(int i=1;i<=n;i++) cin>>x[i];
	vector<vector<int>> dist(n+1,vector<int>(n+1,1e18)),cnt(n+1,vector<int>(n+1,0));
	for(int i=1,k=1;i<=n;i++)
	{
		while(k<i&&x[i]-x[k]>d) k++;
		for(int j=k;j<i;j++)
		{
			dist[j][i]=cnt[j][i]=1;
			for(int u=1;u<k;u++)
			{
				if(dist[u][i]>dist[u][j]+1)
				{
					dist[u][i]=dist[u][j]+1;
					cnt[u][i]=cnt[u][j];
				}
				else if(dist[u][i]==dist[u][j]+1)
				{
					cnt[u][i]+=cnt[u][j];
				}
			}
		}
		for(int u=1;u<k;u++) if(cnt[u][i]==2) ans++;
	}
	//for(int i=1;i<=n;i++) {for(int j=1;j<=n;j++) cout<<dist[i][j]<<" ";cout<<"\n";}cout<<"\n";
	//for(int i=1;i<=n;i++) {for(int j=1;j<=n;j++) cout<<cnt[i][j]<<" ";cout<<"\n";}
	cout<<ans<<"\n";
}
signed main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>c>>t;
	while(t--) solve();
	return 0;
}
