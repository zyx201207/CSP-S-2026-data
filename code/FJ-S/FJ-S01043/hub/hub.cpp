#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
const int maxn=1e6+5;
vector<int> g[maxn];int n,k;
vector<int> e[maxn];
int cnt[maxn],d[maxn];
int s[maxn];int m1,m2;
void dfs(int x,int fa)
{
	d[x]=d[fa]+1;
	e[d[x]].push_back(x); int ss=g[x].size();
	for(int i=0;i<ss;i++)
	{
		int v=g[x][i];
		if(v==fa) continue;
		dfs(v,x);
		s[x]+=s[v];
	}
}
bool check(int x)
{
	int ss=e[x].size();
	for(int j=0;j<ss;j++)
	{
		if(s[e[x][j]]>=m1)
		{
			m2=m1;
			m1=s[e[x][j]];
		}
		else if(s[e[x][j]]>=m2)
		{			
			m2=s[e[x][j]];
		}
	}
	return m1+m2>=k;
}
signed main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int C,T;cin>>C>>T;
	while(T--)
	{
		cin>>n>>k;
		for(int i=1;i<=n;i++) g[i].clear();
		for(int i=1;i<=n;i++) 
		{
			int u,v;cin>>u>>v;
			g[u].push_back(v);g[v].push_back(u);
		}
		if(k==n) {cout<<0<<endl;continue;}
		int ans=LLONG_MAX;
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++) e[j].clear();
			dfs(i,0);
			int l=0,r=n+1;
			while(l!=r-1)
			{
				int mid=(l+r)>>1;
				if(check(mid)) l=mid;
				else r=mid;
			}
			ans=min(ans,l);
		}
		cout<<ans<<endl;
	}
	return 0;
}

