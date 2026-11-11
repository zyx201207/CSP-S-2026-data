#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N=500010;
ll a[N],sum[N],m,n,res=0;
int main(){
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
		int l=1,r=i,mid;
		ll t,ans=i;
		while(l<=r){
			mid=l+(r-l)/2;
			t=(i-mid+1)*a[i]-(sum[i]-sum[mid-1]);
			if(t>m){
				l=mid+1;
			}
			else if(t<=m){
				ans=mid;
				//cout<<i<<" "<<mid<<"\n";
				r=mid-1;
			}
		}
		res=max(res,i-ans+1);
	}
	cout<<res;
	return 0;
} 
