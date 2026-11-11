#include <bits/stdc++.h>
using namespace std;
#define int long long
int a[500002],sum[500002];
void solve(){
	int n,m;cin>>n>>m;
	for (int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n);
	sum[1]=a[1];
	for (int i=2;i<=n;i++) sum[i]=sum[i-1]+a[i];
	int ans=1;
	for (int i=2;i<=n;i++){
		int l=1,r=i-1;
		int cur=i;
		while (l<=r){
			int mid=(l+r)>>1;
			if ((i-mid)*a[i]-(sum[i-1]-sum[mid-1])<=m) cur=mid,r=mid-1;
			else l=mid+1;
		}
		ans=max(ans,i-cur+1);
	}
	cout<<ans<<endl;
} 
signed main(){
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int _=1;
//	cin>>_;
	while (_--) solve();
	return 0;
}

