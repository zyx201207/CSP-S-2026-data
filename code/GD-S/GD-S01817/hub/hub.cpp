#include <bits/stdc++.h>
#define start_code signed main(){
#define stop_code return 0;}
#define elif else if
#define Tests int T;for(cin>>T;T --;)
#define infile(x) freopen(#x".in","r",stdin)
#define outfile(x) freopen(#x".out","w",stdout)
#define ansfile(x) freopen(#x".ans","w",stdout)
#define openfile(x) (infile(x),outfile(x))
#define fastio() (ios::sync_with_stdio(0),cin.tie(0),cout.tie(0))
//#define int long long
using namespace std;
namespace solution1
{
	typedef pair<int,int> pii;
	const int N = 105;
	int n,k,t[5],len,val[N],ans; bitset<N> f; pii e[N]; vector<int> g[N];
	struct dsu
	{
		int fa[N],si[N];
		void init() {for (int i = 1;i <= n;i ++) fa[i] = i,si[i] = 1;}
		int find(int x) {return fa[x]==x ? x : fa[x]=find(fa[x]);}
		void unite(int x,int y)
		{
//			cerr<<"in [unite]\n";
			x = find(x),y = find(y);
//			cerr<<"step 1 [unite]\n";
			if (x == y) return ;
//			cerr<<"step 2 [unite]\n";
			if (si[x] < si[y]) swap(x,y);
//			cerr<<"step 3 [unite]\n";
			fa[y] = x,si[x] += si[y];
//			cerr<<"out [unite]\n";
		}
	} d;
	void calc(int x,int fa)
	{
		if (f[x]) val[x] = 0;
		val[x] = min(val[x],val[fa]+1);
		for (auto v:g[x]) if (v != fa) calc(v,x);
	}
	void dfs(int dep,int cnt)
	{
		if (dep > n)
		{
			if (cnt != k) return ;
//			cerr<<"achieved : cnt = "<<cnt<<'\n';
//			for (int i = 1;i <= n;i ++) cerr<<f[i];
//			cerr<<'\n';
			d.init(),len = 0;
			for (int i = 1;i < n;i ++)
				if (f[e[i].first] && f[e[i].second])
					d.unite(e[i].first,e[i].second);
//			cerr<<"passed\n";
			for (int i = 1;i <= n;i ++)
				if (d.fa[i]==i && f[i])
				{
					t[++len] = i;
					if (len > 2) return ;
				}
//			cerr<<"succeed\n";
			memset(val,0x3f,sizeof val);
			for (int i = 1;i <= len;i ++) calc(t[i],0);
			int weight = 0; 
			for (int i = 1;i <= n;i ++) weight = max(weight,val[i]);
			ans = min(weight,ans);
			return ;
		}
		if (cnt == k)
		{
			for (int i = dep;i <= n;i ++) f.reset(i);
//			cerr<<"cut1 ---- ";
			return dfs(n+1,k);
		}
		if (n-dep+1+cnt == k)
		{
			for (int i = dep;i <= n;i ++) f.set(i);
//			cerr<<"cut2 ---- ";
			return dfs(n+1,k);
		}
		f.reset(dep),dfs(dep+1,cnt);
		f.set(dep),dfs(dep+1,cnt+1);
	}
	start_code
	Tests
	{
		cin>>n>>k,ans = INT_MAX;
		for (int i = 1,u,v;i < n;i ++)
			cin>>u>>v,e[i] = make_pair(u,v),g[u].push_back(v),g[v].push_back(u);
//		cerr<<"alive\n";
		dfs(1,0);
		cout<<ans<<'\n';
		for (int i = 1;i <= n;i ++) g[i].clear(),e[i] = {0,0};
	}
	stop_code
}
int CID;
start_code
openfile(hub);
fastio();
cin>>CID;
solution1::main();
stop_code
