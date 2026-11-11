#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[500005],b[500005],sum[500005],ans;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++) sum[i]=sum[i-1]+a[i];
	for(int i=1;i<n;i++) b[n]+=a[n]-a[i];
	for(int i=n-1;i>=1;i--) b[i]=b[i+1]-i*(a[i+1]-a[i]);
	for(int i=1;i<=n;i++){
		int l=0,r=i+1;
		while(l<r-1){
			int mid=(l+r)>>1;
			int k=b[i]-(a[i]*mid-sum[mid]);
			if(k>m) l=mid;
			else r=mid;
		}
		int kl=b[i]-(a[i]*l-sum[l]);
		if(kl<=m) ans=max(ans,i-l);
		else {
			int kr=b[i]-(a[i]*r-sum[r]);
			if(kr<=m) ans=max(ans,i-r);
		}
	}
	cout<<ans;
	return 0;
}