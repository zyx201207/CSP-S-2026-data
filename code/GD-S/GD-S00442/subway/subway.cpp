#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
#define int long long
int n,m,d,q;
int zt[N];
struct asd
{
	int to,x;
	bool operator<(asd const& db) const 
	{
		return x<db.x;
	}
};
vector<asd> a[N+500];
int dis[N+500];
priority_queue<asd> que;
int dij(int s,int t)
{
	memset(dis,0x3f,sizeof(dis));
	dis[s+500]=0;
	que.push({s+500,0});
	while(!que.empty())
	{
		asd nw=que.top();
		que.pop();
		for(auto i:a[nw.to])
		{
			if(dis[i.to]>dis[nw.to]+i.x)
			{
				dis[i.to]=dis[nw.to]+i.x;
				que.push({i.to,dis[i.to]});
			}
		}
	}
	return zt[s]+zt[t]+dis[t+500];
}
int f[2005][2005];
signed main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int C;
	cin>>C;
	cin>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
		cin>>zt[i];
	for(int i=1;i<=n;i++)
	{
		int len;
		cin>>len;
		for(int j=1;j<=len;j++)
		{
			int v,w;
			cin>>v>>w;
			a[i].push_back({v+500,w});
			a[v+500].push_back({i,w});
		} 
	}
	while(q--)
	{
		int s,t;
		cin>>s>>t;
		cout<<dij(s,t)<<'\n'; 
	}
	return 0;
}
