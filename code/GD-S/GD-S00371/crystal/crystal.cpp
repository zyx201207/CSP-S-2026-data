#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[500005],ans,pr[500005];
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++) pr[i]=pr[i-1]+a[i];
	for(int i=n;i>=1;i--){
		if(ans>i) break;
		int l=1,r=i;
		while(l<r){
			int mid=(l+r)>>1;
			int t=(i-mid+1)*a[i]-(pr[i]-pr[mid-1]);
			if(t<=m) r=mid;
			else l=mid+1;
		}
		ans=max(ans,i-r+1);
	}
	cout<<ans;
	return 0;
} 
