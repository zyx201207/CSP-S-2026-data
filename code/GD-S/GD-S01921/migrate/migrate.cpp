#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,t,n,d,a[5001],dis[5001][5001],cnt[5001][5001],ans;
void solve()
{
	cin>>n>>d,ans=0;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) dis[i][j]=(i!=j)*n,cnt[i][j]=0;
	for(int i=1;i<=n;i++) for(int j=i+1;j<=n&&a[j]-a[i]<=d;j++) dis[i][j]=cnt[i][j]=1;
	for(int k=1;k<=n;k++) for(int i=1;i<=n;i++) if(i!=k) for(int j=1;j<=n;j++) if(j!=k&&j!=i)
	{
		if(dis[i][k]+dis[k][j]<dis[i][j]) dis[i][j]=dis[i][k]+dis[k][j],cnt[i][j]=cnt[i][k]*cnt[k][j];
		else if(dis[i][k]+dis[k][j]==dis[i][j]) cnt[i][j]+=cnt[i][k]*cnt[k][j];
	}
	for(int i=1;i<=n;i++) for(int j=i+1;j<=n;j++) ans+=(cnt[i][j]==2);
	cout<<ans<<'\n';
}
signed main()
{
	freopen("migrate.in","r",stdin),freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>c>>t;
	while(t--) solve();
}
