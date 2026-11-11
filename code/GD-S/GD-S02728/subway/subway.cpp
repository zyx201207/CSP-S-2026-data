#include<bits/stdc++.h>
using namespace std;
int _,n,m,d,p; //m条线，n个站 
long long w[500005];
vector<pair<int,long long>> b[500505];
struct ask{
	int x,y;
	int id;
}q[100005];
long long ans[100005],dist[500505];
bool vis[500505];
void di(int x)
{
	priority_queue<pair<long long,int>,vector<pair<long long,int>>,greater<pair<long long,int>>> pq;
	pq.push({0,x});
	for(int i=1;i<=n;i++)
	{
		dist[i]=0x6f6f6f6f6f6f6f6f;
		vis[i]=0;
	}
	for(int i=1;i<=m;i++)
	{
		dist[i+500000]=0x6f6f6f6f6f6f6f6f;
		vis[i+500000]=0;
	}
	dist[x]=0;
	vis[x]=1;
	while(!pq.empty())
	{
		int pos=pq.top().second;
		pq.pop();
		vis[x]=0;
		for(int i=0;i<b[pos].size();i++)
		{
			int npos=b[pos][i].first;
			int ncost=b[pos][i].second;
			if(dist[npos]>dist[pos]+ncost)
			{
				dist[npos]=dist[pos]+ncost;
				if(!vis[npos])
				{
					pq.push({dist[npos],npos});
					vis[npos]=1;
				}
			}
		}
	}
}
signed main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>_>>m>>n>>d>>p;
	for(int i=1;i<=n;i++)
	cin>>w[i];
	for(int i=1;i<=m;i++)
	{
		int k;
		cin>>k;
		for(int j=1;j<=k;j++)
		{
			int state,time;
			cin>>state>>time;
			b[i+500000].push_back({state,time});
			b[state].push_back({i+500000,time});
		}
	}
	for(int i=1;i<=p;i++)
	{
		cin>>q[i].x>>q[i].y;
		if(q[i].x>q[i].y)
		swap(q[i].x,q[i].y);
		q[i].id=i;	
	}
	sort(q,q+p+1,[](ask x,ask y){
		return x.x<y.x;	
	});
	for(int i=1;i<=p;i++)
	{
		if(q[i].x==q[i-1].x)
		ans[q[i].id]=dist[q[i].y]+w[q[i].x]+w[q[i].y];
		else
		{
			di(q[i].x);
			ans[q[i].id]=dist[q[i].y]+w[q[i].x]+w[q[i].y];
		}
	}
	for(int i=1;i<=p;i++)
	cout<<ans[i]<<"\n";
}
/*
步行： 
初始：地铁口-W->对应站厅->对应线站台 
换站：A站厅->A对应线站台->B对应线站台->B站厅 
aij：i线经过aij站 
tij：i线到aij站厅的时间 
站编号:1~500000
线编号：500001~500501 

0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
2 1

72652800
*/
