#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define freop(s) freopen(s".in","r",stdin);freopen(s".out","w",stdout);
#define endl '\n'
#define inf 0x7f7f7f7f
#define lb(x) ((x)&-(x))
#define pii pair<int,int>
#define fir first
#define sec second
#define mkp make_pair
const int N=1e6+5;
int C,T,n,k,ans,fl[N],vis[N];
vector<int> g[N];

int dfs(int u,int fa){
	if(fl[u]) return 0;
	int mn=inf;
	for(int v:g[u]) if(v^fa)
		mn=min(mn,dfs(v,u)+1);
	return mn;
}
void dfs2(int u,int fa){
	if(!fl[u]) return ;
	vis[u]=1;
	for(int v:g[u]) if(v^fa) dfs2(v,u);
}
inline void js(int x,int sm){
	if(sm==k){
		int mx=0,flag=0;
		for(int i = 1;i<=n;++i) vis[i]=0;
		for(int i = 1;i<=n&&flag<=2;++i){
			if(!vis[i]&&fl[i]) ++flag,dfs2(i,0);
			mx=max(mx,dfs(i,0));
		}
		ans=min(ans,mx);
		return ;
	}
	if(n-x>=sm) fl[x]=0,js(x+1,sm);
	fl[x]=1,js(x+1,sm+1),fl[x]=0;
}

int main(){
	cin.tie(0)->ios::sync_with_stdio(0);
	cout.tie(0);
	freopen("hub1.in","r",stdin);
//↑以上为初始化↑
//-------------------------------------------------
	cin >> C >> T;
	while(T--){
		cin >> n >> k,ans=inf;
		for(int i = 1;i<=n;++i) g[i].clear();
		for(int i = 1,u,v;i<n;++i)
			cin >> u >> v,
			g[u].push_back(v),
			g[v].push_back(u);
		js(1,0),cout << ans << endl;
	}
	return 0;
}

