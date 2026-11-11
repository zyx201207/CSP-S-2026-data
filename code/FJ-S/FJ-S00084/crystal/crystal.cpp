#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[500010],b[500010];
int sum[500010];
int n,m;
signed main() {
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) {
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++) {
		sum[i]=sum[i-1]+a[i];
	}
	int res=-1;
	for(int i=1;i<=n;i++) {
		//mei ju cheng wei na ge shu.
		int l=1,r=i;//kai shi de qi dian wei zhi
		int ans=-1;
		//cout<<"di "<<i<<" ge:\n";
		while(l<=r) {
			int mid=l+r>>1;
			int ss=sum[i]-sum[i-mid-1];
			//cout<<"len:"<<mid<<" "<<a[i]*mid-(ss)<<"\n";
			if(a[i]*mid-(ss)<=m) {
				ans=mid;
				l=mid+1;
			}else {
				r=mid-1;
			}
		}
		//cout<<ans<<"\n";
		res=max(res,ans);
	}
	cout<<res;
	return 0;
}
/*
5 8
-3 -1 2 2 7
*/
