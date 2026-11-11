#include<bits/stdc++.h>
using namespace std;
const long long N=5e5+10;
long long n,m;
long long ans;
long long a[N];
long long sum[N];
bool check(long long x){
	long long it=lower_bound(a+1,a+n+1,x)-a-1;
	if(x*it*1LL-sum[it]>m){
		return 0;
	}else{
		return 1;
	}
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin.tie(0)->sync_with_stdio(0);
	cin>>n;
	cin>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
//	for(int i=1;i<=n;i++){
//		cout<<a[i]<<" ";
//	}
	for(int i=1;i<=n;i++){
		sum[i]=sum[i-1]+a[i];
	}
	long long l=a[1],r=a[n];
	while(l<r){
		long long mid=(l+r)>>1;
		if(check(mid)==1){
			l=mid+1;
		}else{
			r=mid-1;
			ans=mid;
		}
	}
	//cout<<ans;
	long long it=lower_bound(a+1,a+n+1,ans)-a-1;
	cout<<it;
	return 0;
}
