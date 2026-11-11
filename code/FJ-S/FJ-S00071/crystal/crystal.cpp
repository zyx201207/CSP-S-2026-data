#include<bits/stdc++.h>
typedef long long ll;
typedef unsigned long long ull;
typedef double db;
typedef long double ldb;
typedef __int128 i8;
const ll N=5e5+5,inf=(1ll<<60),mod=1e9+7;
using namespace std;
ll a[N],v[N],s[N];
ll n,m;  
ll ans=-inf;
bool check(ll x,ll d){
	return a[d]*(d-x+1)-(s[d]-s[x-1])<=m;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		s[i]=a[i]+s[i-1];
	}
	for(int i=1;i<=n;i++){
		ll l=1,r=i;
		while(r-l>=1){
			ll mid=(l+r)>>1;
			if(check(mid,i)){
				r=mid;
			}else{
				l=mid+1;
			}
		}
		ans=max(ans,i-l+1);
	}
	cout<<ans;
	//ÓÖÊÇÒ»²Í~ 
}

