#include<bits/stdc++.h>
using namespace std;
#define FILE(x) freopen(x".in","r",stdin);freopen(x".out","w",stdout)
#define ll long long
const int N=5e5+10;
ll a[N],sum[N];
ll n,m;
ll ans;
ll query(ll l,ll r){
	return sum[r]-sum[l-1];
}
int main(){
	FILE("crystal"); 
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin>>n>>m;
	ans=1;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n);
	ll l=1;
	for(ll i=1;i<=n;i++){
		sum[i]=sum[i-1]+a[i];
		while(l<=i&&(i-l+1)*a[i]-query(l,i)>m) l++;
		ans=max(ans,i-l+1);
	}
	cout<<ans;
	return 0;
} 
