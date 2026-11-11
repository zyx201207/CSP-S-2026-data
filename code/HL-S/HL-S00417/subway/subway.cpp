#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int z=5e5+9999+9;
int c,n,m,d,q,mod=9999;
struct node
{
	int s,v;
};
vector<pair<int,int> >e[z];
int w[z],dis[z];
bool vis[z];
void dfs(int s)
{
	queue<int>q;
	memset(vis,0,sizeof vis);
	memset(dis,0x3f,sizeof dis);
	dis[s]=0;
	q.push(s);
	vis[s]=1;
	while(!q.empty())
	{
		int u=q.front();
		vis[u]=0;
		q.pop();
		for(auto& edge:e[u])
		{
			int v=edge.first,_w=edge.second;
			if(dis[v]>dis[u]+_w)
			{
				dis[v]=dis[u]+_w;
				if(vis[v]==0)
				{
					vis[v]=1;
					q.push(v);
				}
			}
		}
	}
}
signed main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
	{
		cin>>w[i];
	}
	for(int i=1;i<=n;i++)
	{
		int t1,t2,t3;
		cin>>t1;
		for(int j=1;j<=t1;j++)
		{
			cin>>t2>>t3;
			e[i].push_back({t2+mod,t3});
			e[t2+mod].push_back({i,t3});
		}
	}
	for(int i=1;i<=q;i++)
	{
		int t4,t5;
		cin>>t4>>t5;
		dfs(t4+mod);
		cout<<dis[t5+mod]+w[t4]+w[t5]<<endl;
	}
	return 0;
}
/*


*/

