#include<bits/stdc++.h>
using namespace std;
int dis[5001][5001];
int a[114514];
vector<pair<int,int> > G[114514];
int c,t;
void dij(int s)
{
	priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > > pq;
	memset(dis,0x3f,sizeof(dis));
	pq.push({0,s});
	dis[s][s]=0;
	while(!pq.empty())
	{
		int u = pq.top().second;
		pq.pop();
		for(auto e : G[u])
		{
			int v = e.first;
			int w = e.second;
			if(dis[s][v] > dis[s][u] + w)
			{
				dis[s][v] = dis[s][u]+w;
				pq.push({dis[s][v],v});
			}
		}
	}
}
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--)
	{
		memset(a,0,sizeof(a));
		int n,d;
		cin>>n>>d;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
		}
		for(int i=1;i<=n;i++)
		{
			for(int j=i+1;j<=n;j++)
			{
				if(i==j)continue;
				int len = abs(a[i]-a[j]);
				cout<<len<<endl;
				if(len<=d)
				{
					G[a[i]].push_back({a[j],len});
				}
			}
		}
		for(int i=1;i<=n;i++)
		{
			dij(i);
		}//666¿¨ÁË 
		cout<<dis[1][n]-dis[1][2]<<endl;
	}
}
/*
±ù±ù±ù±ù ±ù±ù±ù±ù ±ù±ù±ù±ù ±ù±ù±ù±ù ±ù±ù±ù±ù ±ù±ù±ù±ù ±ù±ù±ù±ù ±ù±ù±ù±ù 
±ù±ù±ù±ù ±ù±ù±ù±ù ±ù±ù±ù±ù ±ù±ù±ù±ù ±ù±ù±ù±ù ±ù±ù±ù±ù ±ù±ù±ù±ù ±ù±ù±ù±ù 
±ù±ù±ù±ù ±ù±ù±ù±ù ±ù±ù±ù±ù ±ù±ù±ù±ù ±ù±ù±ù±ù ±ù±ù±ù±ù ±ù±ù±ù±ù ±ù±ù±ù±ù 
±ù±ù±ù±ù ±ù±ù±ù±ù ±ù±ù±ù±ù ±ù±ù±ù±ù ±ù±ù±ù±ù ±ù±ù±ù±ù ±ù±ù±ù±ù ±ù±ù±ù±ù
±ù±ù±ù±ù ±ù±ù±ù±ù ±ù±ù±ù±ù ±ù±ù±ù±ù ±ù±ù±ù±ù ±ù±ù±ù±ù ±ù±ù±ù±ù ±ù±ù±ù±ù 
±ù±ù±ù±ù ±ù±ù±ù±ù ±ù±ù±ù±ù ±ù±ù±ù±ù ±ù±ù±ù±ù ±ù±ù±ù±ù ±ù±ù±ù±ù ±ù±ù±ù±ù 
±ù±ù±ù±ù ±ù±ù±ù±ù ±ù±ù±ù±ù ±ù±ù±ù±ù ±ù±ù±ù±ù ±ù±ù±ù±ù ±ù±ù±ù±ù ±ù±ù±ù±ù 
¹Ø×¢Âå¹È1007461Ð»Ð»ß÷ 
*/
