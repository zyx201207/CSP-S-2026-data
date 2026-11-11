#include<iostream>
#include<algorithm>
#define int long long
using namespace std;
int a[500005],sum[500005],m;
bool check(int mid,int x){
	return m>=(a[x]*(x-mid+1)-sum[x]+sum[mid-1]);
}
int binary(int x){
	int l=1,r=x,ans=x;
	while(l<=r){
		int mid=l+(r-l)/2;
		if(check(mid,x)){
			r=mid-1;
			ans=mid;
		}
		else l=mid+1;
	}
	return ans;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];	
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		sum[i]=sum[i-1]+a[i];
	}
	int ans=0;
	for(int i=1;i<=n;i++){
		ans=max(ans,i-binary(i)+1);
	}
	cout<<ans;
	return 0;
} 
