#include<bits/stdc++.h>
using namespace std;
const int maxn=505;
const long long INF=1e18;
long long t[maxn];
int p[maxn],a[maxn];
long long e[2000][2000];
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>t[i];
	int x,u,h;
	for(int i=1;i<=m+n;i++)
	for(int j=1;j<=m+n;j++)
	e[i][j]=INF;
	for(int i=1;i<=n;i++)
	{
		cin>>x;
		for(int j=1;j<=x;j++)
		{
			cin>>u>>h;
			e[u][i+m]=e[i+m][u]=h;
		}
	}
	
	for(int k=1;k<=m+n;k++)
	{
		for(int i=1;i<=m+n;i++)
		{
			for(int j=1;j<=m+n;j++)
			{
				e[i][j]=min(e[i][j],e[i][k]+e[k][j]);
			}
		}
	}
	int v;
	for(int i=1;i<=q;i++)
	{
		cin>>u>>v;
		cout<<e[u][v]+t[u]+t[v]<<"\n";
	}
	return 0;
}
