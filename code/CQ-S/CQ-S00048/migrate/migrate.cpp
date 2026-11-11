#include<bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define rep(i,l,r) for(int i=(l); i<=(r); ++i)
#define drep(i,r,l) for(int i=(r); i>=(l); --i)
using namespace std;
#define int long long
#define cls(f,v) memset(f,v,n+2<<3)
const int N=2e6+5;
int cas,n,D,S,a[N],nxt[N];
int t[N],c[N],d[N];
void DP(int i) {
	cls(t,0x3f); rep(j,i,n) t[j]=0;
	cls(c,0),cls(d,0),c[i]=d[i]=1;
	int k=i;
	drep(j,i-1,1) {
		k=min(k,nxt[j]);
		while(k>j+1&&t[k-1]==t[nxt[j]]) --k;
		c[j]=min(d[k]-d[nxt[j]+1],3LL),t[j]=t[nxt[j]]+1,d[j]=d[j+1]+c[j];
	}
}
void sol() {
	cin>>n>>D,S=0;
	rep(i,1,n) cin>>a[i];
	int j=1; rep(i,1,n) {
		while(j<n&&a[j+1]-a[i]<=D) ++j;
		nxt[i]=j;
	}
	if(n<=5000) rep(i,1,n) {DP(i); rep(j,1,i-1) S+=c[j]==2;}
	else if(cas==11||cas==12) {DP(n); rep(i,1,n-1) S+=(c[j]==2)*i;}
//	rep(p,3,n) if((j=nxt[p])==nxt[p-1]&&nxt[p-2]<j) for(int i:E[p]) S+=f[i]*g[j];
//	rep(i,1,n) rep(j,i+1,n) S+=w[i][j]==2;
	cout<<S<<'\n';
}
signed main() {
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	FASTIO;
	int _; cin>>cas>>_;
	while(_--) sol();
}
