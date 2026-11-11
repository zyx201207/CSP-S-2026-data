#include<bits/stdc++.h>

using namespace std;
const int N=2e6+10;
const long long INF=1e18;

long long d,dis[N][N];
int c,t,n;
long long cnt;
/*void add(int a,int b)
{
	e[idx]=b;ne[idx]=h[a];h[a]=idx++;
}*/

struct Edge
{
	int a,b,w;
}e[N];

int solve()
{
	
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(i==j) dis[i][j]=0;
			else dis[i][j]=INF;
		}
	}
	for(int k=1;k<=n;k++)
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				dis[i][j]=min(dis[i][k]+dis[k][j],dis[i][j]);
				cnt++;
			}
		}
	}
	return cnt;
}

int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	cin>>c>>t;
	int ans=0;
	while(t--)
	{
		cin>>n>>d;
		for(int i=1;i<=n;i++)
		{
			cin>>e[i].a>>e[i].b;
			e[i].w=e[i].b-e[i].a;
		}
		solve();
		if(cnt==n*n*n-1) ans++;
		cout<<ans<<"\n";
	}
	return 0;
}
