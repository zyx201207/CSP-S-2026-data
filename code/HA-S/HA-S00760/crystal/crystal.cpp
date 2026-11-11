#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[500005],sum[500005];
bool check(int x){
	for(int i=1;i<=n-x+1;i++){
		int j=i+x-1;
		if(a[j]*(x-1)-(sum[j-1]-sum[i-1])<=m)return 1;
	}
	return 0;
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		sum[i]=sum[i-1]+a[i];
	}
	int l=0,r=n,ans=0;
	while(l<=r){
		int mid=(l+r)>>1;
		if(check(mid)){
			ans=mid;
			l=mid+1;
		}
		else
			r=mid-1;
	}
	cout<<ans;
	return 0;
}
