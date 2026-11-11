#include <bits/stdc++.h>
using namespace std;
#define int long long

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

const int N=2e6+10;

int p[12];
ll c,t,n,d,x[N],f[N],g[N],h[N],to[N];

int get(int x, int y, int z) {
	int c=0;
	rep(i,0,2) p[++c]=to[x]-i,p[++c]=to[y]-i,p[++c]=to[z]-i;
	sort(p+1,p+c+1);
	if(p[c-2]<p[c-1]&&p[c-1]<p[c])
		return f[p[c]]+max(x,to[y])-max(x,to[z]);
	else if(p[c-1]==p[c]&&p[c-2]<p[c-1])
		return g[p[c]]+max(x,to[y])-max(x,to[z]);
	else if(p[c-1]<p[c]&&p[c-1]==p[c-2])
		return h[p[c]]+max(x,to[y])-max(x,to[z]);
	return max(x,to[y])-max(x,to[z]);
}

void Mainsolve() {
	cin>>n>>d;
	rep(i,1,n)cin>>x[i];
	int j=n;
	per(i,n,1) {
		while(x[j]-x[i]>d) --j;
		to[i]=j;
	}
	to[0]=0;
	rep(i,1,n+5) f[i]=g[i]=h[i]=0;
	ll ans=0;
	per(i,n-1,1) {
		if(i<to[i]) {
			ans+=f[to[i]];
			if(i>=2) 
				f[i]=get(i,i-1,i-2),
				g[i]=get(i,i,i-1),
				h[i]=get(i,i-1,i-1);
		}
	}
	cout<<ans<<"\n";
}

bool MemoryED;
signed main() {
//	system("fc migrate.out migrate5.ans"); exit(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	
	cerr<<fixed<<setprecision(6)<<(&MemoryST-&MemoryED)/1024.0/1024.0<<"MB\n";
	
	int T=1,c; cin>>c>>T;
	while(T--) Mainsolve();
	
	cerr<<"\n"<<1e3*clock()/CLOCKS_PER_SEC<<"ms\n";
	return 0;
}
