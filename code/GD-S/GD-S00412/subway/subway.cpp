#include <bits/stdc++.h>
using namespace std;
#define ll long long 
const ll N = 1e3+7;
const ll INF= LONG_MAX;
int c,n,m,d,q;
int w[N];
ll t[N][N];
int a[N][N];
int k[N];
ll dist[N][N];
void init()
{
	for(int i=1;i<=m;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if(i == j) dist[i][j] = 0;
			else dist[i][j] = INF;
//			cout<<"dist["<<i<<"]["<<j<<"]= "<<dist[i][j]<<endl;
		}
	}
}
int main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	
	cin>>c>>n>>m>>d>>q;
	init();
	for(int i=1;i<=m;i++)
	{
		cin>>w[i];
	}
	for(int i=1;i<=n;i++)
	{
		cin>>k[i];
		for(int j=1;j<=k[i];j++)
		{
			cin>>a[i][j]>>t[i][j];
		}
		
		for(int j=1;j<=k[i];j++)//j -> z
		{
			for(int z=1;z<=k[i];z++)
			{
				dist[a[i][j]][a[i][z]]= min(dist[a[i][j]][a[i][z]],t[i][j] + t[i][z]);
//				cout<<"dist["<<a[i][j]<<"]["<<a[i][z]<<"]= "<<dist[a[i][j]][a[i][z]]<<endl;
			}
		}
	}
//	for(int op = 1;op<=n;op++)
	for(int i=1;i<=m;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if(i == j) continue;
			for(int q=1;q<=m;q++)
			{
				dist[i][j] = min(dist[i][j],dist[i][q] + dist[q][j]);
//				cout<<"dist["<<i<<"]["<<j<<"]= "<<dist[i][j]<<endl;
			}
			
		}
	}
	for(int i=0;i<q;i++)
	{
		int x,y;
		cin>>x>>y;
		cout<<dist[x][y] + w[x] + w[y]<<endl;
	}

//    cout<<dist[1][2]<<" "<<dist[2][3]<<" "<<dist[1][3];
	return 0;
}
/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2


32
17


0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3
*/
