#include<iostream>
#include<cstdio>
using namespace std;
const int N=2000;
const int M=500+10;
int c,n,m,d,q;
long long dis[N][N];
long long w[N];
int cnt;
long long t[N][M];
int a[N];
bool vis[N][N];
int sum;
int b[N];
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio();
	cin.tie(0);
	cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<N;i++)
		for(int j=1;j<N;j++)
			dis[i][j]=1e10;
	cnt=m;
	for(int i=1;i<=m;i++)
		cin>>w[i];
	for(int i=1,x,y,w;i<=n;i++)
	{
		cin>>x;
		for(int j=1;j<=x;j++)
			cin>>a[j]>>t[i][j],vis[a[j]][i]=1;
		cnt++;
		for(int j=1;j<=x;j++)
			dis[cnt][a[j]]=dis[a[j]][cnt]=min(dis[cnt][a[j]],t[i][j]);
	}
	for(int i=1;i<=m;i++)
	{
		sum=0;
		for(int j=1;j<=n;j++)
		{
			if(vis[i][j])
				b[++sum]=j+cnt;
		}
		for(int j=1;j<=sum;j++)
		{
			for(int k=1;k<=sum;k++)
			{
				if(j==k)continue;
				dis[b[j]][b[k]]=dis[b[k]][b[j]]=0;
			}
		}
	}
	for(int k=1;k<=cnt;k++)
		for(int i=1;i<=cnt;i++)
			for(int j=1;j<=cnt;j++)
				dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
	while(q--)
	{
		int x,y;
		cin>>x>>y;
		cout<<dis[x][y]+w[x]+w[y]<<'\n';
	}
	return 0;
}
/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2

0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3
*/
