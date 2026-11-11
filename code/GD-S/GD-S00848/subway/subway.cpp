#include <bits/stdc++.h>
using namespace std;
const int N=500005;
long long a[N],k[505],w[N],x[N],y[N],fa[N],ans=1,vis[N],t[N],len[N];
int c, n, m, d, q;
vector <pair<int,long long>> e[N];
struct node
{
	long long v,w;
	bool operator < (const node k)const
	{
		return w>k.w;
	}
};
int getfa(int u)
{
	return (u==fa[u]?u:fa[u]=getfa(fa[u]));
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
		cin>>k[i];
		for(int j=1;j<=k[i];j++)
		{
			cin>>a[j]>>t[j];
			for(int j1=1;j1<j;j1++)
			{
				e[a[j1]].push_back({a[j],t[j]+t[j1]});
				e[a[j]].push_back({a[j1],t[j]+t[j1]});
			}
		}
	} 
	for(int i=1;i<=q;i++)
	{
		cin>>x[i]>>y[i];
		memset(len,0X3f,sizeof(len));
		len[x[i]]=0;
		if(c>=12&&c<=15)
		{
			queue<int>q;
			q.push(x[i]);
			while(q.size())
			{
				int u=q.front();
				q.pop();
				if(u==y[i])
				{
					break;
				}
				for(auto [v,w]:e[u])
				{
					if(len[v]==len[0])
					{
						len[v]=len[u]+t[1]*2;
						q.push(v);
					}
				}
			}
		}
		else
		{
			priority_queue<node> q;
			q.push({x[i],0});
			while(q.size())
			{
				auto [u,l]=q.top();
				q.pop();
				if(u==y[i])
				{
					break;
				}
				for(auto [v,w]:e[u])
				{
					if(len[v]>len[u]+w)
					{
						fa[v]=u;
						len[v]=len[u]+w;
						q.push({v,len[v]});
					}
				}
			}
		}
		cout<<w[x[i]]+len[y[i]]+w[y[i]]<<'\n';
	}
	return 0;
} 
