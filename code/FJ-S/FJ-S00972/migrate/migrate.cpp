#include<bits/stdc++.h>
using namespace std;
#define int long long
int c,t,n,a[5140],d,sum[5140][5140],sho[5140][5140],ans=0;
void dfs(int u,int fir,int pas)
{ 
	for(int i=u+1;i<=n;i++)
	{
		if(a[i]-a[u]>d) break;
		dfs(i,fir,pas+1);
	}
	if(pas>sho[fir][u]) return;
	sum[fir][u]=((pas==sho[fir][u])?sum[fir][u]+1:1);
	sho[fir][u]=min(sho[fir][u],pas);
}
signed main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>c>>t;
	while(t--)
	{
		memset(sho,127,sizeof sho);
		memset(sum,0,sizeof sum);
		ans=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++) cin>>a[i];
		for(int i=1;i<=n;i++) dfs(i,i,0);
		for(int i=1;i<=n;i++) for(int j=i+1;j<=n;j++) if(sum[i][j]==2) ans++;
		cout<<ans<<endl;
	}
	return 0;
}
