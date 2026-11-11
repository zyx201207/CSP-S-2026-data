#include<bits/stdc++.h>
using namespace std;
long long INF=9223300000000;
struct ed{
	int ve;
	int time;
};
vector<ed> e[500005];
int c,n,m,d,q;
int w[500005];
long long dij(int x,int y)
{
	priority_queue<pair<long long,int> > q;
	q.push({0,x});
	long long time[n+5];
	fill(time+1,time+n+1,INF);
	bool vis[n+5];
	time[x]=0;
	vis[x]=1;
	while(!q.empty())
	{
		auto node=q.top();
		q.pop();
		vis[node.second]=1;
		
		for(ed next : e[node.second])
		{
			if(node.second==next.ve)
			{
				continue;
			}
			if(time[next.ve]<node.first)
			{
				continue;
			}
			if(time[node.second]+next.time<time[next.ve])
			{
				time[next.ve]=time[node.second]+next.time;
				q.push({time[next.ve],next.ve});
			}
		}
	}
	return time[y];
}
int main()
{
	
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
	{
		cin>>w[i];
	}
	for(int i=1;i<=n;i++)
	{
		int k;
		int a1,t1,a2,t2;
		cin>>k>>a1>>t1>>a2>>t2;
		e[a1].push_back({a2,t1+t2});
		e[a2].push_back({a1,t1+t2});
	}
	int q;
	cin>>q;
	
	while(q--)
	{
		int x,y;
		cin>>x>>y;
		cout<<dij(x,y)+w[x]+w[y]<<endl;
	}
	
}
