#include<bits/stdc++.h>
#define ll long long
#define M 510
#define N 500900
using namespace std;
int _,n,m;// n stations and m imaginational stations
ll w[N];
ll dis[M][M];
vector<pair<int,ll>>ve[N];
int read()
{
	char tmp;
	while((tmp=getchar())<'0'||tmp>'9');
	int ans=tmp-'0';
	while((tmp=getchar())>='0'&&tmp<='9')
		ans=ans*10+tmp-'0';
	return ans;
}
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	read();
	m=read();
	n=read();
	read();
	_=read();
	for(int i=1;i<=n;i++)
		w[i]=read();
	for(int i=n+1;i<=n+m;i++)
	{
		int sz=read();
		for(int j=1;j<=sz;j++)
		{
			int v=read();
			int t=read();
			ve[v].push_back({i,t});
		}
	}
	for(int i=1;i<=m;i++)
		for(int j=1;j<=m;j++)
			dis[i][j]=(i!=j)*4e18;
	for(int i=1;i<=n;i++)
		for(auto &U:ve[i])
			for(auto &V:ve[i])
			{
				int u=U.first-n,v=V.first-n;
				ll w1=U.second,w2=V.second;
				dis[u][v]=dis[v][u]=min(dis[u][v],w1+w2);
			}
	for(int k=1;k<=m;k++)
		for(int i=1;i<=m;i++)
			for(int j=1;j<=m;j++)
				dis[i][j]=dis[j][i]=min(dis[i][j],dis[i][k]+dis[k][j]);
	while(_--)
	{
		int u=read(),v=read();
		ll ans=4e18;
		for(auto &U:ve[u])
			for(auto &V:ve[v])
			{
				int uu=U.first-n,vv=V.first-n;
				ll w1=U.second,w2=V.second;
				ans=min(ans,w1+w2+dis[uu][vv]);
			}
		cout<<ans+w[u]+w[v]<<'\n';
	}
	return 0;
}
