#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
const ll N=500005;
const ll M=1000000000005;
ll n,a[N],m,l,r,sum,ans=1;
bool sorter(ll a,ll b){
	a+=N;b+=N;
	return(a<b);
}
int main(){//r-l+1:¸öÊý
freopen("crystal.in","r",stdin); 
freopen("crystal.out","w",stdout); 
	cin>>n>>m;
	for(ll i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n);
	for(;r<n;){
		for(;(sum>m)&&(l<=r);){
			sum-=a[r]-a[l];
			l+=1;	
		}
		if(l<=r){
			ans=max(ans,r-l+1);
			if(r==n-1)break;
		}
		sum+=(r-l+1)*(a[r+1]-a[r]);
		r+=1;
	}
	cout<<ans;
}
