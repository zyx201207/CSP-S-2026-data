#include<bits/stdc++.h>
#define int long long
//Accepted at 15:09
using namespace std;
const int N=5e5+5;
int n,m,a[N],sum[N],ans;
signed main() {
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) {
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++) {
		sum[i]=sum[i-1]+a[i];
	}
	for(int i=1;i<=n;i++) {
		int l=1,r=n-1;
		while(l<r) {
			int mid=(l+r)/2;
			int cost=(i-mid)*a[i]-(sum[i-1]-sum[mid-1]);
			if(cost<=m) r=mid;
			else l=mid+1;
		}
		ans=max(ans,i-l+1);
	}
	cout<<ans;
	return 0;
}
