#include<bits/stdc++.h>
using namespace std;
const int N=1005,M=25;
struct Node
{
	int name,sum,tt[M],lin[M];
};
struct Line
{
	Node point[N];
	int num;
}b[M];
int c,n,m,d,q,ans,kt[N],way[M][M],dist[N][N];
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)	cin>>kt[i];
	for(int i=1;i<=n;i++)
	{
		cin>>b[i].num;
		for(int j=1;j<=b[i].num;j++)
		{
			cin>>b[i].point[j].name>>b[i].point[j].tt[i];
			b[i].point[j].sum++;
			b[i].point[j].lin[b[i].point[j].sum]=i;
			dis[b[i].point[j-1]][b[i].point[j]]=kt[j]+kt[j-1]+b[i].point[j-1].tt[i]+b[i].point[j].tt[i];
			dis[b[i].point[j]][b[i].point[j-1]]=dis[b[i].point[j-1]][b[i].point[j]];
			for(int k=1;k<=j;k++)	dis[b[i].point[k]][b[i].point[j]]=dis[b[i].point[k]][b[i].point[j-1]]+dis[b[i].point[j-1]][b[i].point[j]]-kt[j-1]-b[i].point[j-1].tt[i];
		}
	}
	for(int i=1;i<=q;i++)
	{
		int st,en;
		cin>>st>>en;
		
	}
}
