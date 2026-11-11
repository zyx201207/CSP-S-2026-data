#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,n,m,d,q;
struct node
{
	int v,w;
	bool operator >(const node &x)const{
		return w<x.w;
	}
};
int w[600005];
int k[505];
int sz[600005];
int dis1[600005];
int vis[600005];
vector<node> e[600005];
void dij(int s)
{
	for(int i=1;i<=m*(2+n)+n;i++)
	{
		dis1[i]=1e18;
		vis[i]=0;
	}
	priority_queue<node,vector<node>,greater<node>> q;
	
	dis1[s]=0;
	vis[s]=1;
	q.push({s,0});
	while(!q.empty())
	{
		node s=q.top();
		q.pop();
		
		int now=s.v;
		int w=s.w;
		for(int i=0;i<e[now].size();i++)
		{
			int son=e[now][i].v;
			if(dis1[son]>w+e[now][i].w)
			{
				dis1[son]=w+e[now][i].w;
				if(!vis[son])
				q.push({son,dis1[son]});
				vis[son]=1;
			}
		}
	}
}
int dis[1005][1005];
signed main(){
	ios::sync_with_stdio(0),cin.tie(0); 
	
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
	{
		cin>>w[i];
		e[(i-1)*(1+1+n)+1].push_back({(i-1)*(1+1+n)+2,w[i]});
		e[(i-1)*(1+1+n)+2].push_back({(i-1)*(1+1+n)+1,w[i]});
	}
	for(int i=1;i<=n;i++)
	{
		cin>>k[i];
		for(int j=1;j<=k[i];j++)
		{
			int a,t;
			cin>>a>>t;
			int zt=(a-1)*(1+1+n)+2+1+sz[a];
			int dtt=(a-1)*(1+1+n)+2;
			sz[a]++;
			e[zt].push_back({dtt,t});
			e[dtt].push_back({zt,t});
			
			int sup=m*(2+n)+i;
			e[zt].push_back({sup,0});
			e[sup].push_back({zt,0});
		}
	}
	
	for(int i=1;i<=m;i++)
	{
		dij((i-1)*(1+1+n)+1);
		for(int j=1;j<=m;j++)
		{
			dis[i][j]=dis1[(j-1)*(1+1+n)+1];
		}
	}
	
	while(q--)
	{
		int st,nd;
		cin>>st>>nd;
		cout<<dis[st][nd]<<"\n";
	}
	
	
	
	return 0;
}
