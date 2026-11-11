#include<bits/stdc++.h>
using namespace std;
const int maxn=5e5+5,inf=2e9;
struct node
{
	int v,w;
};
vector<node> g[maxn],tmp(maxn);
int c,m,n,d,q,w[maxn];
int kru(int x,int y)
{
	vector<int> dis(maxn,inf),vis(maxn,0);
	queue<int> q;
	q.push(x);
	dis[x]=0;
	vis[x]=0;
	while(!q.empty())
	{
		int now=q.front();
		q.pop();
		if(vis[now])
		{
			continue;
		}
		vis[now]=1;
		for(int i=0;i<(int)g[now].size();i++)
		{
			int to=g[now][i].v;
			int w=g[now][i].w;
			if(dis[to]>dis[now]+w)
			{
				dis[to]=dis[now]+w;
				q.push(to);
			}
		}
	}
	return dis[y];
}
int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>c>>m>>n>>d>>q;
    for(int i=1;i<=n;i++)
    {
		cin>>w[i];
	}
	for(int i=1;i<=m;i++)
	{
		int k;
		cin>>k;
		tmp.clear(); 
		for(int j=1;j<=k;j++)
		{
			int a,t;
			cin>>a>>t;
			tmp.push_back({a,t});
		}
		for(int p=0;p<(int)tmp.size();p++)
		{
			int sp=tmp[p].v;
			int wp=tmp[p].w;
			for(int q=0;q<(int)tmp.size();q++)
			{
				if(p==q)
				{
					continue;
				}
				int sq=tmp[q].v;
				int wq=tmp[q].w;
				g[sp].push_back({sq,wq+wp});
			}
		}
	}
	while(q--)
	{
		int x,y;
		cin>>x>>y;
		cout<<w[x]+w[y]+kru(x,y)<<"\n";
	}    
    return 0;
}
