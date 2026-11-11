#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,a[510005],sum[510005],len,ans;
signed main() {
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)sum[i]=sum[i-1]+a[i];
	for(int i=1;i<=n;i++) {
		int l=1,r=i;
		while(l<r) {
			int mid=(l+r)/2;
			if(a[i]*(i-mid+1)-sum[i]+sum[mid-1]<=m)r=mid;
			else l=mid+1;
		}
		ans=max(ans,i-l+1);
	}
	cout<<ans<<endl;
	return 0;
}
