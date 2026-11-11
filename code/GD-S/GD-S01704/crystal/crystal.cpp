#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll maxn=1e6+7;
ll n,m,ans,a[maxn],s[maxn];
bool check(ll x){
	for(ll l=1,r=l+x-1;r<=n;l++,r++){
		if(a[r]*x-(s[r]-s[l-1])<=m){
			return true;
		}
	}
	return false;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(ll i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(ll i=1;i<=n;i++){
		s[i]=s[i-1]+a[i];
	}
	ll l=1,r=n,mid;
	while(l<=r){
		mid=(l+r)/2;
		if(check(mid)){
			l=mid+1;
			ans=mid;
		}
		else{
			r=mid-1;
		}
	}
	cout<<ans<<endl;
	return 0;
}