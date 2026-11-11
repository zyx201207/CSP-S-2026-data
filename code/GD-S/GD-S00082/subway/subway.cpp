#include<bits/stdc++.h>
using namespace std;
struct pos
{
	int to,w;
	bool operator < (const pos x)const{
		return x.w<w;
	}
};
int a[500010];
int c,n,m,d,q;
vector<pos>g[500010];
priority_queue<pos>r;
bool vis[500010];
long long dis[500010];
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
	{
		cin>>a[i];
	}
	int t;
	for(int i=1;i<=n;i++)
	{
		cin>>t;
		for(int j=1,u,v;j<=t;j++)
		{
			cin>>u>>v;
			g[i].push_back({u,v});
		}
	}
	int st,fnl;
	while(q--)
	{
		cin>>st>>fnl;
		for(int i=1;i<=m;i++)
		{
			dis[i]=1000000000010;
			vis[i]=0;
		}
		dis[st]=0;
		r.push({st,0});
		while(!r.empty())
		{
			pos k=r.top();
			r.pop();
			if(vis[k.to])continue;
			vis[k.to]=1;
			for(pos i:g[k.to])
			{
				if(dis[i.to]>dis[k.to]+i.w)
				{
					dis[i.to]=dis[k.to]+i.w;
					if(!vis[i.to])r.push({i.to,dis[i.to]});
				}
			}
		}
		cout<<dis[fnl]+a[st]+a[fnl]<<endl;
	}
	return 0;
}
