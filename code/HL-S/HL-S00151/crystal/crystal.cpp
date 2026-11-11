#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
const ll N=5e5+10;
ll n,m;
ll a[N];
int main() {
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	bool k=true;
	ll d;
	for(ll i=1;i<=n;i++){
		cin>>a[i];
		if(i==2){
			d=a[i]-a[i-1];
		}
		if(i>=2){
			if(a[i]-a[i-1]!=d){
				k=false;
			}
		}
	}
	if(k){
		cout<<m/d;
		return 0;
	}
	sort(a+1,a+n+1);
	ll ans=-1;
	for(ll i=1;i<=n;i++){
		ll cnt=m;
		ll sum=0;
		for(int j=i;j>=1;j--){
			ll k=a[i]-a[j];
			if(cnt>=k){
				cnt-=k;
				sum++;
			}
			else{
				break;
			}
		}
		ans=max(ans,sum);
	}
	cout<<ans;
	return 0;
}

