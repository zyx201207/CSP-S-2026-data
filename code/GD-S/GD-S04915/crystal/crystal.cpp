#include <bits/stdc++.h>
#define fo(i,l,r) for(int i(l); i<=(r); ++i)
#define fu(i,l,r) for(int i(l); i<(r); ++i)
#define fd(i,l,r) for(int i(l); i>=(r); --i)
#define File "crystal"
#define pb push_back
#define il inline
#define sz(x) (int((x).size()))
using namespace std;
using ll=long long;
const int N=5e5+5;
int n;
ll m,a[N],s[N];
int main() {
	freopen(File".in","r",stdin);
	freopen(File".out","w",stdout);
	cin.tie(0)->sync_with_stdio(0);
	cin>>n>>m;
	fo(i,1,n) cin>>a[i];
	sort(a+1,a+n+1);
	fo(i,1,n) s[i]=s[i-1]+a[i];
	int j=1,ans=0;
	fo(i,1,n) {
		while(a[i]*(i-j+1ll)-(s[i]-s[j-1])>m) ++j;
		ans=max(ans,i-j+1);
	}
	cout<<ans<<'\n';
	return 0;
}