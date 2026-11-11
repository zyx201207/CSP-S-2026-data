#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=1e6+10;
ll n,m;
bool cmp(ll o,ll p){
	return o<p;
}
ll a[N];
bool check(ll p){
	ll num=0;
	for(ll i=1;i<=p;i++){
		num+=a[i];
	}
	if(m>=a[p]*p-num)return 1;
	for(ll i=p+1;i<=n;i++){
		num-=a[i-p];
		num+=a[i];
		if(m>=a[i]*p-num)return 1;
	}
	return 0;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(ll i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1,cmp);
	ll last=0;
	ll l=0,r=n,ans=0;
	while(l<=r){
		ll mid=(l+r)/2;
		if(check(mid)){
			ans=mid;
			l=mid+1;
		}else r=mid-1;
	}

	cout<<ans;
	return 0;
} 
/*
5 5
1 2 4 8 
可以不从1开始 
*/
