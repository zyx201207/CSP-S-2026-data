#include<bits/stdc++.h>
using namespace std;
int w[500005];
struct jgt
{
	int wh,nd;
};
vector<jgt> g[505];
int ans=0;
bool vis[500005];
stack<pair<int,int>> st;
bool decc=false;
void bfs(int x,int y,int step,int now)
{
	if(now==y) 
	{
		decc=true;
		return;
	}
	if(step>5000) return;
	if(decc)
	{
		return;
	}
	for(int i=0;i<g[now].size();i++)
	{
		st.push({now,g[now][i].wh});
		bfs(x,y,step+1,g[now][i].wh);
		st.pop();
	}
}
signed main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int c,n,m,d,q; cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++)
	{
		int k; cin>>k;
		for(int j=1;j<=k;j++) 
		{
			int v,x;
			cin>>v>>x;
			g[i].push_back({v,x});
			g[v].push_back({i,x});
		}
	}
	while(q--)
	{
		int x,y;
		cin>>x>>y;
		ans=0;
		decc=false;
		memset(vis,0,sizeof(vis));
		bfs(x,y,0,x);
		while(!st.empty())
		{
			auto temp=st.top();
			int t1=temp.first,t2=temp.second;
			ans+=g[t1][t2].nd;
		}
		cout<<ans+w[x]+w[y]<<endl;
	}
	return 0;
}
