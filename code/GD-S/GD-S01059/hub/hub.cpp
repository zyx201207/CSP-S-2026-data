#include<bits/stdc++.h>
#define psb push_back

using namespace std;

const int N=1000010;
int n,K; vector<int> G[N]; int dep[N];
int id[N], fa[N];
bool del[N];

void Dfs(int u,int fat)
{
	dep[u]=dep[fat]+1; fa[u]=fat;
	for (int v : G[u])
	{
		if (v==fat) continue;
		Dfs(v,u);
	}
}

void dfs_del(int u,int fat,int dist)
{
	del[u]=true; if (!dist) return;
	for (int v : G[u]) if (v!=fat) dfs_del(v,u,dist-1);
}

bool check(int mid)
{
	for (int i=1;i<=n;i++) del[i]=false;
	int cnt=0;
	for (int i=1;i<=n;i++) 
	{
		int u=id[i];
		if (del[u]) continue;
		if (cnt==K) return false;
		for (int j=0;j<mid;j++) if (fa[u]) u=fa[u];
		dfs_del(u,0,mid); cnt++;
	}
	return true;
} 

void solve()
{
	cin >> n >> K;
	for (int i=1;i<=n;i++) G[i].clear();
	for (int i=1;i<n;i++)
	{
		int u,v; cin >> u >> v;
		G[u].psb(v), G[v].psb(u);
	}
	Dfs(1,0);
	for (int i=1;i<=n;i++) id[i]=i;
	sort(id+1,id+n+1,[&](int x,int y){ return dep[x]>dep[y]; }); 
	int l=0,r=n,res;
	while (l<=r)
	{
		int mid=(l+r)>>1;
		if (check(mid)) res=mid,r=mid-1;
		else l=mid+1;
	}
	cout << res << "\n";
}

int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	
	int c,T; cin >> c >> T;
	while (T--) solve();
	 
	
	return 0;
}

