#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e6+5;
const int INF=0x3f3f3f3f3f3f3f3fLL;
struct edges{
	int u,v;
}e[N];
int c,t;
int n,k;
int fa[N];
vector<int> g[N];
set<int> st;
int dfs(int u,int father)
{
	if(st.find(u)!=st.end()) return 0;
	int cnt=INF;
	for(auto v:g[u])
	{
		if(v==father) continue;
		cnt=min(dfs(v,u),cnt);
	}
	return cnt+1;
}
int find(int k)
{
	if(fa[k]==k) return k;
	return fa[k]=find(fa[k]);
}
signed main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>c>>t;
	while(t--)
	{
		cin>>n>>k;
		for(int i=1;i<=n;i++) g[i].clear();
		for(int i=1;i<n;i++)
		{
			cin>>e[i].u>>e[i].v;
			g[e[i].u].push_back(e[i].v);
			g[e[i].v].push_back(e[i].u);
		}
		int ans=INF;
		for(int mask=1;mask<(1<<n);mask++)
		{
			int cnt=0;
			for(int i=0;i<n;i++) if(mask&(1<<i)) cnt++;
			if(cnt!=k) continue;
			st.clear();
			for(int i=0;i<n;i++) if(mask&(1<<i)) st.insert(i+1);
			for(int i=1;i<=n;i++) fa[i]=i;
			for(int i=1;i<n;i++)
			{
				int u=e[i].u,v=e[i].v;
				if(st.find(u)==st.end()||st.find(v)==st.end()) continue;
				fa[find(u)]=find(v);
			}
			int kk=0;
			for(int i=1;i<=n;i++) if(st.find(i)!=st.end()&&fa[i]==i) kk++;
			if(kk>2) continue;
			int maxx=0;
			for(int i=1;i<=n;i++)
			{
				if(st.find(i)==st.end())
				{
					maxx=max(maxx,dfs(i,0));
				}
			}
			ans=min(ans,maxx);
		}
		cout<<ans<<'\n';
	}
	return 0;
}
