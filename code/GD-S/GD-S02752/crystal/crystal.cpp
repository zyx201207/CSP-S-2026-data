#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int ma=5e5+5;
bool cmp(ll a,ll b){
	return a<b;
}
ll n,m,a[ma];
unsigned long long sum[ma];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		a[i]+=1000000000000;
	}
	sort(a+1,a+1+n,cmp);
	for(int i=1;i<=n;i++){
		sum[i]=sum[i-1]+a[i];
	}
	ll ans=1;
	for(int i=1;i<=n;i++){
		ll l=1,r=i-1;
		while(l<r){
			ll mid=l+(r-l>>1);
			if(a[i]*(i-mid)-(sum[i-1]-sum[mid-1])<=m)r=mid;
			else l=mid+1;
		}
		if(a[i]*(i-l)-(sum[i-1]-sum[l-1])<=m){
			ans=max(ans,i-l+1);
		}
	}
	cout<<ans;
	return 0;
}
/*
*/
