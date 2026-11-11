#include <bits/stdc++.h>
using namespace std;
#define int long long
#define FAST ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
int a[500010],sum[500010];
signed main() {
	FAST
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1; i<=n; i++) {
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1; i<=n; i++) {
		sum[i]=sum[i-1]+a[i];
	}
	int res=0;
	for(int i=1; i<=n; i++) {
		int l=1,r=i,ans=i;
		while(l<=r) {
			int mid=(l+r)/2;
			if(a[i]*(i-mid+1)-(sum[i]-sum[mid-1])<=m) {
				ans=mid;
				r=mid-1;
			} else {
				l=mid+1; 
			}
		}
		res=max(res,i-ans+1);
	}
	cout<<res;
	return 0;
}
