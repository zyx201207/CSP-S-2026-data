#include <bits/stdc++.h>
#define int long long
#define PII pair<int,int>
#define upp(a,x,y) for(int a=x;a<=y;a++)
#define dww(a,x,y) for(int a=x;a>=y;a--)
#define pb push_back
#define x first
#define y second
#define endl '\n'
using namespace std;
const int N=1e6+10,INF=0x3f3f3f3f3f3f3f3f;
int cid,n,K;
vector<int> e[N];
int fa[N],st[N],dep[N],ans=INF;
void dfs(int u,int ff) {
	for(auto j:e[u]) {
		if(j==ff) continue;
		fa[j]=u;
		dep[j]=dep[u]+1; 
		dfs(j,u);
	}
}
int dist(int x,int y) {
	int sum=0;
	if(dep[x]<dep[y]) swap(x,y);
	while(dep[x]>dep[y]) {
		sum++;
		x=fa[x];
	}
	while(x!=y) {
		x=fa[x],y=fa[y];
		sum+=2;
	}
	return sum;
}
int work() {
	int res=0;
	upp(i,1,n) {
		upp(j,1,n) {
			if(!st[j]) continue;
			res=max(res,dist(i,j));
		}
	}
	return res;
}
void solve() {
	ans=INF;
	cin>>n;
	upp(i,1,n) e[i].clear(); 
	upp(i,1,n-1) {
		int x,y;cin>>x>>y;
		e[x].pb(y);
		e[y].pb(x);
	}
	dep[1]=1;
	dfs(1,-1);
	upp(i,0,(1<<n)-1) {
		upp(j,1,n) st[j]=0;
		upp(j,0,n-1) if(i>>j&1) st[j+1]=1;
		ans=min(ans,work());
	}
	cout<<ans<<endl;
}
signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int tt;cin>>cid>>tt;
	while(tt--) solve();
	return 0;
}

