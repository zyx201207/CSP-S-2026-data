#include "bits/stdc++.h"
using namespace std;
#define int long long
int n,m;
int a[500005],sum[500005];
signed main(void){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++) sum[i]=sum[i-1]+a[i];
	int ans=0;
	for(int i=1;i<=n;i++){
		int l=1,r=i;
		while(l<r){
			int mid=(l+r)>>1;
			if((a[i]*(i-mid+1)-(sum[i]-sum[mid-1]))<=m) r=mid;
			else l=mid+1;
		}
		if((a[i]*(i-l+1)-(sum[i]-sum[l-1]))<=m) ans=max(ans,i-l+1);
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
} 
