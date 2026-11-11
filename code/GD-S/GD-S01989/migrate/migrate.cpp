#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define eb emplace_back
using namespace std;
using ll= long long;
using ull= unsigned long long;
const int N=2000005,inf=1000000000;
vector<int> g[N];
int n,f[N],dis[N];
ll x[N],d;
inline void bfs(const int s) {
	fill(dis,dis+n+1,inf);
	dis[s]=0;
	queue<int> q;
	q.push(s),f[s]=1;
	while(q.size()) {
		const int u=q.front(); q.pop();
		for(int& v: g[u]) {
			if(dis[v]>dis[u]+1)
				f[v]=0,dis[v]=dis[u]+1,q.push(v);
			if(dis[v]==dis[u]+1)
				f[v]=min(3,f[v]+f[u]);
		}
	}
}
inline void mian10() {
	cin>>n>>d;
	for(int i=1;i<=n;i++) cin>>x[i],g[i].clear();
	for(int i=1;i<=n;i++)
		for(int j=1;j<i;j++)
			if(x[i]-x[j]<=d)
				g[j].pb(i);
	ll ans=0;
	for(int u=1;u<=n;u++) {
		bfs(u);
		for(int v=u+1;v<=n;v++)
			if(f[v]==2)
				ans++;
	}
	cout<<ans<<'\n';
}
inline void mianA() {
	cin>>n>>d;
	for(int i=1;i<=n;i++) cin>>x[i];
	if(n==1) return cout<<"0\n",void();
	const ll cha=x[2]-x[1];
	const int mx=min(d/cha,n-1ll);
	if(mx<=1) return cout<<"0\n",void();
	ll ans=0;
	for(int u=1;u+mx+mx-1<=n;u++) { // (u, u+2mx-1<=n)
//		ans+=min(u+mx+mx-1,n)-(u+mx+1)+1;
//		cerr<<u+mx+mx-1<<','<<u+mx+1<<'\n';
//		cerr<<min(u+1,n)<<' '<<min(u+mx-1,n)<<'\n';
		ans++;
	}
	cout<<ans<<'\n';
}
inline bool can(int i,int j) {
	if(i<1||i>n||j<1||j>n) return 0;
	return x[i]-x[j]<=d&&x[j]-x[i]<=d;
}
ll p1[N],p2[N];
inline void mianB() {
	cin>>n>>d;
	for(int i=1;i<=n;i++) cin>>x[i];
	int ts=0;
	for(int i=1;i<=n;i++)
		if(can(1,i)&&can(i,n))
			ts=i;
	ll l1=0,l2=0,r1=0,r2=0;
	for(int i=1;i<ts;i++) {
		if(can(i,ts+1)) l1++;
		else l2++;
		p1[i]=l1,p2[i]=l2;
	}
	ll ans=0;
	for(int i=n;i>ts;i--) {
		if(can(i,ts-1)) r1++;
		else r2++;
		const int p=lower_bound(x+1,x+n+1,x[i]-d)-x-1;
		ans+=p1[p]*r2+p2[p]*r1;
	}
	cout<<ans<<'\n';
}
inline void mian() {
	mian10();
}
signed main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,TwT=1;
	cin>>c>>TwT;
	if(c<=10) {
		while(TwT--) mian10();
		return 0;
	}
	if(c<=12) {
		while(TwT--) mianA();
		return 0;
	}
	if(c<=14) {
		while(TwT--) mianB();
		return 0;
	}
	while(TwT--) mian();
	return 0;
}
/*
1 6
2 7
3 8
4 9
5 10
*/
