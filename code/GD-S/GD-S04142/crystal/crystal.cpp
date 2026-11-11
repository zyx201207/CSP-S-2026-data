#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m;
ll xz[500005];
pair<ll,ll> op[500005];
int main(){
	freopen("crystal4.in","r",stdin);
	cin>>n>>m;
	ll a[n+5];
	for(ll i = 1;i <= n;i++){
		cout<<a[i];
	}
	sort(a+1,a+n);
	for(ll i = 2;i <= n;i++){
		xz[i-1] = a[i] - a[i-1];
		xz[i-1] *= i-1;
		op[i-1].first = op[i-2].first+xz[i-1];
		op[i-1].second = op[i-2].second+xz[i-1]/(i-1);
	}
	// first ->pay,second->sum
	ll maxget = LLONG_MIN;
	for(ll i = 1;i < n;i++){
		ll get = 0,sum = op[i].second,pay = op[i].first,pay1 = op[i].first;
		for(ll j = i;j >= 1;j--){
			if(pay <= m || pay1 <= m){
				get = j+1;
				break;
			}
			pay1 -= op[i-j].second;
			pay -= xz[j];
		}
		maxget = max(get,maxget);
	}
	cout<<maxget;
	//freopen("crystal.out","w",stdout);
	return 0;
}
