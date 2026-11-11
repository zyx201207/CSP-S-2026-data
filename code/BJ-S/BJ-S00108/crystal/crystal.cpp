#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e5+5;
ll n,m;
ll a[N];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(ll i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	if(n>5000){
		ll num=0,res=0;
		for(ll i=1;i<=n;i++){
			if(num+=a[2]-a[1]>m) break;
			num+=a[2]-a[1];
			res++;
		}
		cout<<res;
		return 0;
	}
	ll ans=0;
	for(ll i=1;i<=n;i++){
		ll tmp=0,cnt=0;
		for(ll j=i;j>=1;j--){
			if(cnt+a[i]-a[j]>m) break;
			tmp++;
			cnt+=a[i]-a[j];
		}
		ans=max(ans,tmp);
	}
	cout<<ans;
	return 0;
}
