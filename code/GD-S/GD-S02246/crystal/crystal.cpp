#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=5e5+10;
ll n,m,a[N],sum[N],ans;
ll solve(ll i,ll x){
	ll k=i,l=1,r=i,mid=0;
	while(l<=r){
		mid=l+r>>1;
		if(x*(i-mid)-sum[i-1]+sum[mid-1]>m) l=mid+1;
		else r=mid-1,k=mid; 
	}
	return i-k+1;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++) sum[i]=sum[i-1]+a[i];
	for(ll i=1;i<=n;i++){
		ans=max(ans,solve(i,a[i]));
	}
	cout<<ans;
	return 0;
} 
