#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e5+5;
ll n,m,ans=-2e9;
ll a[N],s[N];
bool check(ll x,ll i){
	ll t=a[i]*(i-x+1)-(s[i]-s[x-1]);
	return t<=m;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];		
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++) s[i]=s[i-1]+a[i];
	for(int i=1;i<=n;i++){
		ll l=1,r=i,mid,as;
		while(l<=r){
			mid=(l+r)/2;
			if(check(mid,i)){
				as=i-mid+1;
				r=mid-1;
			}else l=mid+1;
		}
		ans=max(ans,as);
	}
	cout<<ans;
	return 0;
}
