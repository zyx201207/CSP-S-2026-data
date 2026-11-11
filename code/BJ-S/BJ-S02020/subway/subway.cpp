#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=555,M=500010;
const ll INF=3000000000000000000;
int c,n,m,d,q,k[N],a,x,y,vis[M];
ll w[M],t,mn=INF;
vector<pair<int,ll> >at[N];
vector<pair<int,int> >v[M];
vector<int>st[M];
map<pair<int,int>,ll>mp;
void dfs(int u,int tg,ll s,int lnn,int bg_ln)
{
	if (u==tg)
	{
		mn=min(mn,s+w[x]+w[y]+mp[make_pair(x,bg_ln)]+mp[make_pair(y,lnn)]);
		return ;
	}
	for (int i=0;i<(int)v[u].size();i++)
	{
		if (vis[v[u][i].first]) continue;
		vis[v[u][i].first]=1;
		if (v[u][i].second==lnn) dfs(v[u][i].first,tg,s,lnn,bg_ln);
		else dfs(v[u][i].first,tg,s+mp[make_pair(u,lnn)]+mp[make_pair(u,v[u][i].second)],v[u][i].second,bg_ln);
		vis[v[u][i].first]=0;
	}
}
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for (int i=1;i<=m;i++)
	{
		cin>>w[i];
	}
	for (int i=1;i<=n;i++)
	{
		cin>>k[i];
		for (int j=1;j<=k[i];j++)
		{
			cin>>a>>t;
			at[i].push_back(make_pair(a,t));
			st[a].push_back(i);
			mp[make_pair(a,i)]=t;
		}
		for (int j=0;j<k[i]-1;j++)
		{
			v[at[i][j].first].push_back(make_pair(at[i][j+1].first,i));
			v[at[i][j+1].first].push_back(make_pair(at[i][j].first,i));
		}
	}
	while (q--)
	{
		memset(vis,0,sizeof(vis));
		cin>>x>>y;
		mn=INF;
		for (int i=0;i<(int)st[x].size();i++)
		{
			dfs(x,y,0,st[x][i],st[x][i]);
		}
		cout<<mn<<'\n';
	}
	return 0;
}

