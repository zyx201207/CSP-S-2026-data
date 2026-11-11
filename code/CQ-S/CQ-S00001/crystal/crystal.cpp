#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[500001],sum[500001],ans;
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		sum[i]=sum[i-1]+a[i];
	}
	for(int i=1;i<=n;i++){
		int l=1,r=i,val=0;
		while(l<=r){
			int mid=l+r>>1;
			if(a[i]*mid-(sum[i]-sum[i-mid])<=m) l=mid+1,val=mid;
			else r=mid-1;
		}
//		for(int j=i;j>=1;j--){
//			sm+=a[i]-a[j];
//			cout<<i<<" "<<j<<" "<<sm<<" "<<a[i]*(i-j+1)-(sum[i]-sum[j-1])<<"\n";
//			assert(sm==a[i]*(i-j+1)-(sum[i]-sum[j-1]));
//			if(sm>m) break;
//			val++;
//		}
		ans=max(ans,val);
	}
	cout<<ans;
	return 0;
}
/*
最好肯定是取一个 a_i。

然后二分一个端点就行。 
*/
