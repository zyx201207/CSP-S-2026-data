#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=505;
const int M=3e5+5;
int c,n,m,d,q;
ll w[M];
int k[M];
int a[N][M];
ll t[N][M];
void solve1()
{
	int qqM=5005;
	ll dis[qqM][qqM];
	for(int i=1;i<=m;i++)
	{
		for(int j=1;j<=i;j++)
		{
			if(i==j)
				dis[i][j]=0;
			else
				dis[i][j]=1e18;
			dis[j][i]=dis[i][j];
		}
	}
	for(int i=1;i<=m;i++)
		cin>>w[i];
	for(int s=1;s<=n;s++)
	{
		cin>>k[s];
		for(int i=1;i<=k[s];i++)
			cin>>a[s][i]>>t[s][i];
		for(int i=1;i<=k[s];i++)
		{
			for(int j=1;j<i;j++)
			{
				int x=a[s][i];
				int y=a[s][j];
//				cout<<x<<" "<<y<<" "<<t[s][i]<<" "<<t[s][j]<<"\n";
				dis[x][y]=min(dis[x][y],t[s][i]+t[s][j]);
				dis[y][x]=dis[x][y];
			}
		}
	}
//	exit(0);	
//	for(int i=1;i<=m;i++)
//		cout<<w[i]<<" ";
//	cout<<"\n";
//	for(int i=1;i<=m;i++)
//	{
//		for(int j=1;j<=m;j++)
//			cout<<setw(5)<<(dis[i][j]==1e18 ? -1 : dis[i][j]);
//		cout<<"\n";
//	}
//	cout<<"===========================\n";
	for(int k=1;k<=m;k++)
	{
		for(int i=1;i<=m;i++)
		{
			for(int j=1;j<=m;j++)
			{
				if(i==j or j==k or k==i)
					continue;
				dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
			}
		}
	}
//	for(int i=1;i<=m;i++)
//	{
//		for(int j=1;j<=m;j++)
//			cout<<setw(5)<<(dis[i][j]==1e18 ? -1 : dis[i][j]);
//		cout<<"\n";
//	}
//	exit(0);
	while(q--)
	{
		int x,y;
		cin>>x>>y;
		cout<<w[x]+w[y]+dis[x][y]<<"\n";
	}
}
void solve2()
{
	vector<pair<int,int> > v[M];
	for(int i=1;i<=m;i++)
	{
		cin>>w[i];
		v[i].clear();
	}
	ll T;
	for(int s=1;s<=n;s++)
	{
		cin>>k[s];
		for(int i=1;i<=k[s];i++)
			cin>>a[s][i]>>t[s][i];
		for(int i=1;i<=k[s];i++)
		{
			if(i!=1)
				v[a[s][i]].push_back(make_pair(a[s][i-1],s));
			if(i!=n)
				v[a[s][i]].push_back(make_pair(a[s][i+1],s));
		}
	}
	T=t[1][1];
	deque<pair<int,int> > qqq;
	ll dis[M];
	int clk=0;
	int vis[M][N];
	while(q--)
	{
		clk++;
		for(int i=1;i<=m;i++)
			dis[i]=1e18;
		int x,y;
		cin>>x>>y;
		dis[x]=T;
		for(pair<int,int> pii:v[x])
			qqq.push_back(make_pair(x,pii.second));
		while(!qqq.empty())
		{
			int u=qqq.front().first;
			int s=qqq.front().second;
			qqq.pop_front();
			if(vis[u][s]==clk)
				continue;
			vis[u][s]=clk;
//			cout<<u<<" "<<s<<" "<<dis[u]<<b"\n";
			for(pair<int,int> pii:v[u])
			{
				int ttt=pii.first;
				int sss=pii.second;
				if(sss==s)
				{
					if(dis[ttt]>dis[u]) 
						dis[ttt]=dis[u],qqq.push_front(make_pair(ttt,sss));
				}	
				else
				{
					if(dis[ttt]>dis[u]+T*2)
						dis[ttt]=dis[u]+T*2,qqq.push_back(make_pair(ttt,sss));
				}	
			}
		}
		cout<<dis[y]+w[x]+w[y]+T<<"\n";
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	if(!(c>=12 and c<=19))
		solve1();
	else if(c>=12 and c<=19)
		solve2();
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
