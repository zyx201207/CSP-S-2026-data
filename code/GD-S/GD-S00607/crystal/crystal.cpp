#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e5+5;
ll n,m;
ll a[N],ans;
bool pd(ll a_[]){
	int x=a[1]-a[0];
	for(int i=2;i<=n;i++){
		if(a[i+1]-a[i]!=x)return 0;
	}
	return 1;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++)scanf("%lld",&a[i]);
	sort(a+1,a+1+n);
	if(pd(a)){
		for(ll i=1;i<n;i++){
			if((2*a[i+1]-(a[1]+a[i]))*i/2<=m)ans=max(ans,i+1);
		}
		cout<<ans;
		return 0;
	}
	for(ll i=1;i<=n;i++){
		ll cnt=0;
		for(ll j=i+1;j<=n;j++){
			cnt+=(a[j]-a[j-1])*(j-i);
			if(cnt<=m)ans=max(ans,j-i+1);
		}
	}
	cout<<ans;
	return 0;
} 
