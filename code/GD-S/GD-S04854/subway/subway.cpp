#include<bits/stdc++.h>
using namespace std;
const int N=505,M=5e5+5;
long long inf=0x3f3f3f3f3f3f3f3f;
int c,n,m,d,q,k[N];
struct edg{int v;long long w;};
basic_string<edg> Gn[N],Gm[M];
long long G[N][N],w[M];
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
		cin>>w[i];
	for(int i=1;i<=n;i++)
	{
		cin>>k[i];
		for(int j=1,v,w;j<=k[i];j++)
			cin>>v>>w,Gn[i]+=edg{v,w},Gm[v]+=edg{i,w};
	}
	for(int i=1;i<=n;i++)
		for(int j=1;j<i;j++)
			G[i][j]=G[j][i]=inf;
	for(int i=1;i<=m;i++)
		for(edg e:Gm[i])
			for(edg ee:Gm[i])
				if(ee.v==e.v) continue;
				else G[ee.v][e.v]=G[e.v][ee.v]=min(G[e.v][ee.v],e.w+ee.w);
	for(int k=1;k<=n;k++)
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				G[j][i]=G[i][j]=min(G[i][j],G[i][k]+G[k][j]);
	for(int x,y;q--;)
	{
		cin>>x>>y;
		long long ans=inf;
		for(edg e:Gm[x])
			for(edg ee:Gm[y])
				ans=min(ans,0ll+e.w+ee.w+G[e.v][ee.v]);
		ans+=w[x]+w[y];
		cout<<ans<<'\n';
	}
}
