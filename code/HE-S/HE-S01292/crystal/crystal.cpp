#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+10;
int n,m,a[N],s[N];
signed main() {
	freopen("crystal.in","r",stdin),freopen("crystal.out","w",stdout);
//	freopen("crystal4.in","r",stdin),freopen("data.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++) s[i]=s[i-1]+a[i];
	int ans=0;
	for(int i=1;i<=n;i++) {
		int l=0,r=i-1,res=i-1;
		while(l<=r) {
			int mid=(l+r)>>1;
			if((i-mid)*a[i]-(s[i]-s[mid])<=m) res=mid,r=mid-1;
			else l=mid+1;
		}
		ans=max(ans,i-res);
	}
	cout<<ans<<"\n";
	return 0;
}
