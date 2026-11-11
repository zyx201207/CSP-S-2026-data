#include<bits/stdc++.h>
#define ll long long

using namespace std;

const int N = 2e6+5;

struct node {
	int v,op;
};
int c,T;
int n;
ll d,a[N];
ll f[N],g[N];
ll son[N];
ll ans;
bool vis[N];
vector<node> e[N]; 

ll gets(ll x,ll y) {
	if(x>y) return 0; 
	ll l=lower_bound(a+1,a+n+1,x)-a;
	ll r=upper_bound(a+1,a+n+1,y)-a-1;
//	cout<<x<<" "<<y<<" "<<l<<" "<<r<<"\n";
	return r-l+1; 
}
void dfs(int u,int fa) {
	vis[u]=1;
	ll cnt=e[u].size();
	for(node x:e[u]) {
		dfs(x.v,u);
		if(cnt<=2) {
			if(x.op==0) f[u]+=g[x.v],g[u]++;
			else f[u]+=f[x.v],g[u]+=g[x.v]+1;
		}
	}
	if(u>2) {
//		cout<<u<<" "<<f[u]<<" "<<g[u]<<"\n";
		ll s1=gets(max(a[u]+1,a[u-1]+d+1),a[fa]),s2=gets(max(a[u]+1,a[u-2]+d+1),a[fa]);
//		cout<<a[u]+1<<" "<<a[u-2]+d+1<<" "<<fa<<"\n";
//		cout<<s1<<" "<<s2<<"\n";
		ans+=g[u]*(s2-s1)+f[u]*s1;
//		cout<<u<<" "<<ans<<"\n";
	}
}
void solve() {
	cin>>n>>d;
	
	ans=0;
	for(int i=1;i<=n;i++)
		e[i].clear(),son[i]=f[i]=g[i]=vis[i]=0; 
	for(int i=1;i<=n;i++)
		cin>>a[i];
	
	int r=0;
	for(int i=1;i<=n;i++) {
		int lst=r;
		while(r<n && a[r+1]-a[i]<=d) ++r;
		if(r==i) continue;
		if(lst<r)e[r].push_back({i,1});
		else e[r].push_back({i,0});
		son[r]++;
	}
	
	for(int i=n;i>=1;i--)
		if(!vis[i]) dfs(i,0);
	cout<<ans<<"\n";
}
int main() {
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	
	cin>>c>>T;
	while(T--) solve();
	return 0;
}
