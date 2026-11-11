#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int MAXN=500100;
ll n,m,a[MAXN],qzh[MAXN];
ll f(ll x){
	ll sum=1e18;
	for(ll i=x;i<=n;i++){
		sum=min(sum,x*a[i]-(qzh[i]-qzh[i-x]));
	}
	return sum;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(ll i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(ll i=1;i<=n;i++) qzh[i]=qzh[i-1]+a[i];
	ll l=1,r=n,ans=0;
	while(l<=r){
		ll mid=l+r>>1;
		if(m>=f(mid)){
			ans=mid;
			l=mid+1;
		}
		else r=mid-1;
	}
	cout<<ans;
	return 0;
}

