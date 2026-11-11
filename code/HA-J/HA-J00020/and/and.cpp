#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll n,m;
vector<ll> a;
ll z;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i = 0;i < n;i++){
		cin>>z;
		a.push_back(z);
	}
	sort(a.begin(),a.end(),[](const ll &aa,const ll &bb){
		for(ll i = 30;i >= 0;i--){
			ll l = aa&i;
			ll r = bb&i;
			if(l != r){
				return l > r;
			}
		}
		return aa > bb;
	});
	ll ans = a[0];
	for(int i = 1;i < m;i++){
		ans&=a[i];
	}
	cout<<ans;
	return 0;
}
