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
signed main() {
	file(crystal);
	cin.tie(nullptr)->sync_with_stdio(false);
	Solve();
}
void Solve() {
	int n; ll K; cin>>n>>K;
	vec<ll> a(n);
	for(int i=0;i<n;i++) cin>>a[i];
	sort(ALL(a));
	int ans=1; ll c=0;
	for(int i=1,j=0;i<n;i++) {
		c+=(i-j)*(a[i]-a[i-1]);
		while(c>K) c-=a[i]-a[j++];
		Max(ans,i-j+1);
	}
	cout<<ans<<endl;
}