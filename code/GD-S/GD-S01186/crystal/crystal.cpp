#include<bits/stdc++.h>
#define ll long long 
using namespace std;
ll n,a[500005],sum[500005],ans;
ll m;
ll max(ll a,ll b){
	return a>b?a:b;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		sum[i]=sum[i-1]+a[i];
	}
	for(int i=1;i<=n;i++){
		ll l=1,r=i;
		while(l<r){
			int mid=(l+r)/2,f=(i-mid+1)*a[i]-sum[i]+sum[mid-1];
			if(f<=m&&
			(i-mid+2)*a[i]-sum[i]+sum[mid-2]>m){
				ans=max(ans,i-mid+1);
				break;
			}else if(f<m){
				r=mid;
			}else{
				l=mid+1;
			}
		}
	} 
	cout<<ans;
	return 0;
}
