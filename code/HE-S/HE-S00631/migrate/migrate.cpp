#include <bits/stdc++.h>
using namespace std;
#define gc getchar()
#define pb push_back
typedef long long ll;
const int N=2e6+6;
ll rd() {
	ll x=0,f=1; char c=gc;
	for(;c<'0'||c>'9';c=gc)if(c=='-')f=-1;
	for(;c>='0'&&c<='9';x=x*10+c-'0',c=gc);
	return x*f;
}
int C,T;
ll n,d,a[N],dis[N],f[N];
bool vis[N];
vector<int> e[N];
queue<pair<ll,ll> > q;
int main() {
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	for(C=rd(),T=rd();T;T--) {
		n=rd(); d=rd();
		for(int i=1;i<=n;i++) a[i]=rd();
		if(1<=C && C<=10) { //O(n^3)
			ll ans=0;
			for(int i=1;i<=n;i++) e[i].clear();
			for(int i=1;i<=n;i++) for(int j=i+1;j<=n;j++)
				if(abs(a[i]-a[j])<=d) e[i].pb(j);
			for(int s=1;s<=n;s++) {
				for(int i=1;i<=n;i++) dis[i]=1e18,vis[i]=0,f[i]=0;
				dis[s]=0; q.push(make_pair(s,0)); f[s]=1;
				while(!q.empty()) {
					int u=q.front().first; q.pop();
					if(vis[u]||f[u]>=3) continue;
					vis[u]=1;
					for(int v:e[u]) {
						if(dis[v]>dis[u]+1) {
							dis[v]=dis[u]+1; f[v]=f[u];
							q.push(make_pair(v,dis[v]));
						} else if(dis[v]==dis[u]+1) f[v]+=f[u];
						f[v]=min(f[v],3LL);
					}
				}
				for(int t=1;t<=n;t++) if(f[t]==2 && s!=t) ans++;
			}
			cout<<ans<<'\n';
		} else if(C==11||C==12) {
			ll ans=0,k=a[2]-a[1],t=d/k;
//			cout<<n<<' '<<k<<' '<<d<<' '<<t<<' ';
			if(t==0||t==1) {cout<<0<<'\n'; continue;}
			for(int i=1;i<=n;i++) ans+=(i+2*t-1<=n?1:0);
			cout<<ans<<'\n';
		}
	}
	return 0;
}
/*
白鸟过河滩，挥一挥一去不回还 

一去不回还，风起水起难靠岸 
*/
