#include <bits/stdc++.h>
#define ll long long
#define pb push_back
using namespace std;
const int N=550,M=5e5+10;
int c,n,m,d,q;
ll w[M],dis[N][N];
vector<int> a[M],t[M];
void solve() {
	cin>>c>>n>>m>>d>>q;
	for (int i=1;i<=m;i++) cin>>w[i];
	for (int i=1;i<=n;i++)
	{
		int k;
		cin>>k;
		while (k--)
		{
			int x,y;
			cin>>x>>y;
			a[x].pb(i),t[x].pb(y);
		}
	}
	memset(dis,0x3f,sizeof(dis));
	for (int i=1;i<=n;i++) dis[i][i]=0;
	for (int i=1;i<=m;i++)
	{
		for (int j=0;j<a[i].size();j++)
		{
			for (int k=j+1;k<a[i].size();k++)
			{
				int a1=a[i][j],a2=a[i][k],t1=t[i][j],t2=t[i][k];
				dis[a1][a2]=dis[a2][a1]=min(dis[a1][a2],1ll*t1+t2); 
//				cout<<a1<<' '<<a2<<endl;
			} 
		}
	}
	for (int k=1;k<=n;k++)
	{
		for (int i=1;i<=n;i++)
		{
			for (int j=1;j<=n;j++) dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]); 
		}
	}
//	for (int i=1;i<=n;i++)
//	{
//		for (int j=1;j<=n;j++) cout<<dis[i][j]<<' ';
//		cout<<'\n';
//	}
	while (q--)
	{
		int u,v;
		cin>>u>>v;
//		cout<<u<<' '<<v<<endl;
		ll ans=1e18;
		for (int i=0;i<a[u].size();i++)
		{
			for (int j=0;j<a[v].size();j++)
			{
				int a1=a[u][i],a2=a[v][j],t1=t[u][i],t2=t[v][j];
				ans=min(ans,w[u]+w[v]+t1+t2+dis[a1][a2]);
			}
		}
		cout<<ans<<'\n';
	} 
}
int main() {
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0);
	solve();
	return 0;
}
