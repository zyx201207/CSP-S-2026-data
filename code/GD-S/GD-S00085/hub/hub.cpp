#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define pii pair<int,int>
#define mkp make_pair
#define pb push_back
#define vi vector<int>
#define rep(i,l,r) for(int i=(l);i<=(r);++i)
#define per(i,r,l) for(int i=(r);i>=(l);--i)
#define vsz(x) (int)x.size()
#define ll long long

bool MemoryST;

const int N=1e6+10;

vi e[N];
int n,k,X,f[N],fl[N],to[N],u[N],v[N];

void dfs1(int u, int fa) {
	int len=0;
	f[u]=1;
	fl[u]=0;
	int v1=0,v2=0;
	for(auto v:e[u]) if(v!=fa) {
		dfs1(v,u);
		if(fl[v]>=X) {
			f[u]+=f[v];
		}
		if(fl[v]+1>=X) {
			if(v1) v2=v; else v1=v;
		}
		fl[u]=max(fl[u],fl[v]+1);
	}
	if((v1&&v2)||!(v1+v2)) to[u]=u;
	else to[u]=v1+v2;
}

int dfs2(int u, int fa, int len) {
	if(len>=X||to[u]==u) return f[u];
	for(auto v:e[u]) if(v!=fa&&v!=to[u]) len=max(len,fl[v]);
	return dfs2(to[u],u,len+1);
}

int get(int u, int v) {
	dfs1(u,v);
	return dfs2(u,v,0);
}

bool chk(int x) {
	X=x;
	rep(i,1,n-1) {
		int s=get(u[i],v[i])+get(v[i],u[i]);
		if(s<=k) return 1;
	}
	return 0;
}

void Mainsolve() {
	cin>>n>>k;
	rep(i,1,n) e[i].clear();
	rep(i,1,n-1)
		cin>>u[i]>>v[i],
		e[u[i]].pb(v[i]),e[v[i]].pb(u[i]);
	if(k==n) {
		cout<<"0\n"; return ;
	}
	int l=1,r=n;
	while(l<r) {
		int mid=(l+r)>>1;
		if(chk(mid)) r=mid; else l=mid+1;
	}
	cout<<l<<"\n";
}

bool MemoryED;
int main() {
//	system("fc hub.out hub3.ans"); exit(0);
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cerr<<fixed<<setprecision(6)<<(&MemoryST-&MemoryED)/1024.0/1024.0<<"MB\n";

	int T=1; cin>>T>>T;
	while(T--) Mainsolve();

	cerr<<"\n"<<1e3*clock()/CLOCKS_PER_SEC<<"ms\n";
	return 0;
}
