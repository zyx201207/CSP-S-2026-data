#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
int n;
ll m,a[500005];
ll sum[500005];
bool cmp(ll x,ll y){
	return x<y;
}
bool check(int num){
	for(int i=1;i+num-1<=n;i++){
		ll t=a[i+num-1]*num-(sum[i+num-1]-sum[i-1]);
		if(t<=m) return true;
	}
	return false;
}
int main(){
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
	int l=1,r=n,res=1;
	while(l<=r){
		int mid=(l+r)/2;
		if(check(mid)){
			l=mid+1;
			res=mid;
		}
		else r=mid-1;
	}
	cout<<res;
	return 0;
}
