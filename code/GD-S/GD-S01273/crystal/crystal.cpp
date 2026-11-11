#include<bits/stdc++.h> 
using namespace std;
#define ll long long
#define fi first
#define se second
#define il inline
const ll P=998244353;
const int N=5e5+10;
ll qp(ll a,ll b=P-2){
	ll res=1;
	for(;b;b>>=1,a=(a*a)%P) if(b&1) res=res*a%P;
	return res;
}
// ------------------------------------------------- //
int n,m; ll a[N],s[N]; int ans;
il bool check(int l,int r){ return (r-l+1)*a[r]-(s[r]-s[l-1])<=m; }
// ------------------------------------------------- //
il void solve(){
	cin>>n>>m;
	for(int i=1;i<=n;++i) cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;++i) s[i]=s[i-1]+a[i];
	for(int l=1,r=1;r<=n;++r){
		while(l<r&&!check(l,r)) ++l;
//		cerr<<"test "<<l<<", "<<r<<" = "<<check(l,r)<<"\n";
		if(check(l,r)) ans=max(ans,r-l+1); // cerr<<"upd ans "<<r-l+1<<"\n";
	}
//	cerr<<"tans = "<<ans;
	cout<<ans;
	return;
}
// ------------------------------------------------- //
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int T=1; //cin>>T;
	while(T--) solve(); 
	return 0;
}
