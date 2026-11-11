#include<bits/stdc++.h>
#define file(F) (void)freopen(#F".in","r",stdin),(void)freopen(#F".out","w",stdout)
#define ALL(x) begin((x)),end((x))
#define lowbit(x) ((x)&-(x))
#define ppc(x) (__builtin_popcountll(x))
using namespace std;
template<typename T> bool Max(T &x,T y) { return x<y&&(x=y,true); }
template<typename T> bool Min(T &x,T y) { return x>y&&(x=y,true); }
template<typename T> T abs(const T &x) { return x>0?x:-x; }
template<typename T> using vec=vector<T>;
template<typename T> using vv=vec<vec<T>>;
template<typename T> using vvv=vec<vv<T>>;
template<typename T> using vvvv=vv<vv<T>>;
using ull=unsigned long long;
using ll=long long;
void Solve();
int CID;
signed main() {
	file(migrate);
	cin.tie(nullptr)->sync_with_stdio(false);
	int T; cin>>CID>>T; while(T--)
	Solve();
}
using block=bitset<5000>;
void Solve() {
	int n; ll K; cin>>n>>K;
	vec<ll> a(n+2);
	for(int i=1;i<=n;i++) cin>>a[i];
	ll a0=a[1];
	for(int i=1;i<=n;i++) a[i]+=a0;
	a[0]=-3e18,a[n+1]=5e18;
	if(n<4) return cout<<"0\n",void();
	vec<int> d(n+2);
	// vec<block> lb(n+2),rb(n+2);
	// for(int i=1;i<=n;i++) {
	// 	lb[i][i]=1,d[i]=d[i+1]=0;
	// 	for(int j=i-1,p=i+1;j>=1;j--) {
	// 		while(a[j]+K<a[p]) p--;
	// 		if(p==j) break;
	// 		d[j]=d[p]+1,lb[i][j]=lb[i][p]&&d[p]!=d[p-1];
	// 	}
	// }
	// for(int i=n;i>=1;i--) {
	// 	rb[i][i]=1,d[i]=d[i-1]=0;
	// 	for(int j=i+1,p=i-1;j<=n;j++) {
	// 		while(a[j]-K>a[p]) p++;
	// 		if(p==j) break;
	// 		d[j]=d[p]+1,rb[i][j]=rb[i][p]&&d[p]!=d[p+1];
	// 	}
	// }
	vec<int> lc(n+2),rc(n+2);
	for(int i=2,p=0,q=0;i<n-1;i++) {
		while(p<i&&a[p]+K<a[i+1]) p++;
		while(q<i&&a[q]+K<a[i+2]) q++;
		if(p==1||p==q) { lc[i]=q-p; continue; }
		vec<bool> b(n+1); int c=q-p;
		d[q]=0;
		for(int j=p;j<q;j++) d[j]=1,b[j]=1;
		if(p<q) {
			for(int j=p-1,k=q;j>=1;j--) {
				while(a[j]+K<a[k]) k--;
				if(k==j) break;
				d[j]=d[k]+1;
				c+=(b[j]=b[k]&&d[k]!=d[k-1]);
			}
		}
		lc[i]=c;
	}
	for(int i=n-1,p=n+1,q=n+1;i>2;i--) {
		while(p>i&&a[p]-K>a[i-1]) p--;
		while(q>i&&a[q]-K>a[i-2]) q--;
		if(p==n||p==q) { rc[i]=p-q; continue; }
		vec<bool> b(n+1); int c=p-q;
		d[q]=0;
		for(int j=p;j>q;j--) d[j]=1,b[j]=1;
		if(p>q) {
			for(int j=p+1,k=q;j<=n;j++) {
				while(a[j]-K>a[k]) k++;
				if(k==j) break;
				d[j]=d[k]+1;
				c+=(b[j]=b[k]&&d[k]!=d[k+1]);
			}
		}
		rc[i]=c;
	}
	ll ans=0;
	for(int i=2;i<n-1;i++) ans+=(ll)lc[i]*rc[i+1];
	cout<<ans<<'\n';
}