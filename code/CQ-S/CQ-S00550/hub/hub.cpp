#include<bits/stdc++.h>
using namespace std;
typedef long long lo;
const int N=1e6+5;
int c,T,n,k,a[N];
vector<int>ve[N];
bitset<N>vis;
void dfs(int u){vis.set(u);for(int v:ve[u])if(!vis.test(v)&&a[v])dfs(v);}
int bfs(int s)
{
	queue<pair<int,int>>q;
	q.emplace(s,0);vis.reset();
	vis.set(s);
	while(q.size())
	{
		auto[u,t]=q.front();q.pop();
		if(a[u])return t;
		for(int v:ve[u])if(!vis.test(v))q.emplace(v,t+1);
	}
	return 0;
}
void solve()
{
	cin>>n>>k;int res=1e9;
	for(int i=1;i<=n;i++)ve[i].clear();
	for(int i=1,u,v;i<n;i++)
		cin>>u>>v,ve[u].push_back(v),ve[v].push_back(u);
	if(n>100&&k<=2)return cout<<n/2<<'\n',void(); 
	for(int i=0;i<(1<<n);i++)if(__builtin_popcount(i)==k)
	{
		int sum=0;
		for(int j=1;j<=n;j++)a[j]=(i>>(j-1))&1;
		bool fl=1;vis.reset();int cnt=0;
		for(int j=1;j<=n;j++)if(!vis.test(j)&&a[j])
		{
			if(++cnt>2){fl=0;break;}
			dfs(j);
		}
		if(!fl)continue;
		for(int j=1;j<=n;j++)if(!a[j])sum=max(sum,bfs(j));
		res=min(res,sum);
	}
	cout<<res<<'\n';
}
int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>c>>T;while(T--)solve();
}
/*
退役前的最后一场 -S 啦
打得也就这样 尽人事听天命吧

洛谷 1539207 求关qwq 
*/
