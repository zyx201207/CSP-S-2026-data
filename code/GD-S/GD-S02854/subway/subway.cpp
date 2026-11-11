#include<bits/stdc++.h>
using namespace std;
const int M=5*1e5+10;
const int N=510;
int c,n,m,d,q;
vector<pair<int,pair<int,int> > > v[M];
int w[M];
vector<int> a[N];
vector<int> t[M];
int k[N];
vector<int> dis[M];
void spfa(int start)
{
	queue<pair<int,int> > q;
	q.push({start,-1});
	dis[start][start]=0;
	while(!q.empty())
	{
		int head=q.front().first;
		int last=q.front().second;
		q.pop();
		for(int i=0;i<v[head].size();i++)	
		{
			int x=v[head][i].first;
			int y=v[head][i].second.first;
			int z=v[head][i].second.second;
			int tmp;
			if(head==start)
				tmp=t[head][x-1];
			else
				tmp=dis[start][head]-t[head][last-1];
			if(x!=last && last!=-1)
				tmp=tmp+t[head][last-1]+t[head][x-1];
			if(tmp+t[y][x-1]<dis[start][y])
				dis[start][y]=tmp+t[y][x-1];
			q.push({y,x});
		}
	}
}
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
		cin>>w[i];
	for(int i=1;i<=n;i++)
	{
		cin>>k[i];
		for(int j=0;j<k[i];j++)
		{
			
			int x,y;
			cin>>x>>y;
			a[i].push_back(x);
			t[a[i][j]].resize(N);
			t[a[i][j]][i-1]=y; 
			if(j>=1)
			{
				v[a[i][j-1]].push_back({i,{a[i][j],j-1}});	
			}
		}
	}	
	for(int i=1;i<=m;i++)
	{
		dis[i].resize(m);
		for(int j=1;j<=m;j++)
			dis[i][j]=1e9;
	}
	for(int i=1;i<=m;i++)
	{
		spfa(i);
	}
	while(q--)
	{
		int x,y;
		cin>>x>>y;
		cout<<w[x]+dis[x][y]+w[y]<<endl;
	}
	return 0;
}
