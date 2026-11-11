#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int K=500010;
int c,n,m,d,q,x,y;
int k[K],w[K];
vector<int> a[510],t[510],a_n[K];
queue< pair<int,ll> > qu;
ll ans;
pair<int,ll> p,pn;
bool vis[K],visn[510];
int an_t(int ta,int tn)
{
	for(int i=0;i<a[tn].size();++i)
	{
		if(a[tn][i]==ta)return t[tn][i];
	}
}
ll bfs()
{
	ans=0x3fffffffffffffff;
	p.first=x,p.second=0;
	vis[x]=true;
	qu.push(p);
	while(!qu.empty())
	{
		p=qu.front();
		qu.pop();
		for(int i=0;i<a_n[p.first].size();++i)
		{
			if(!visn[i])
			{
				
				visn[i]=true;
				p.second+=(ll)(an_t(p.first,a_n[p.first][i]));
				for(int j=0;j<a[a_n[p.first][i]].size();++j)
				{
					if(vis[a[a_n[p.first][i]][j]])continue;
					if(a[a_n[p.first][i]][j]==y)
					{
						ans=min(ans,p.second+t[a_n[p.first][i]][j]);
						p.second-=(ll)(an_t(p.first,a_n[p.first][i]));
						break;
					}
					if(!vis[a[a_n[p.first][i]][j]])
					{
						vis[a[a_n[p.first][i]][j]]=true;
						pn.first=a[a_n[p.first][i]][j];
						pn.second=p.second+(ll)(t[a_n[p.first][i]][j]);
						qu.push(pn);
					}
				}
				p.second-=(ll)(an_t(p.first,a_n[p.first][i]));
				visn[i]=false;
			}
		}
	}
	return ans;
}
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
	for(int i=1;i<=m;++i)scanf("%d",&w[i]);
	for(int i=1;i<=n;++i)
	{
		scanf("%d",&k[i]);
		for(int j=1;j<=k[i];++j)
		{
			scanf("%d%d",&x,&y);
			a[i].push_back(x),t[i].push_back(y),a_n[x].push_back(i);
		}
	}
	while(q--)
	{
		scanf("%d%d",&x,&y);
		printf("%lld\n",bfs()+w[x]+w[y]);
		for(int i=0;i<=n;++i)visn[i]=false;
		for(int i=0;i<=500000;++i)vis[i]=false;
	}
	return 0;
}
