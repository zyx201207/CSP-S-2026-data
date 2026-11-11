#include <bits/stdc++.h>
#define int ll
using namespace std;
using ll= long long;
using ull= unsigned long long;
const int N=500005;
int n;
ll m,s[N],a[N];
inline void mian() {
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++) s[i]=s[i-1]+a[i];
	int ans=0;
	for(int i=1;i<=n;i++) {
		int l=0,r=i-1;
		while(l<r) {
			const int mid=(l+r)>>1;
			if(a[i]*(i-mid)-(s[i]-s[mid])<=m) r=mid;
			else l=mid+1;
		}
		ans=max(ans,i-l);
	}
	cout<<ans;
}
signed main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int TwT=1;
//	cin>>TwT;
	while(TwT--) mian();
	return 0;
}

