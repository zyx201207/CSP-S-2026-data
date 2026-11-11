#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <iterator>
#include <queue>
#include <map>
#include <set>
#include <cmath>
#include <functional>
using namespace std;
using ll = long long;
using ull = unsigned long long;
const ll INF = numeric_limits<ll>::max()/2,NEG_INF = numeric_limits<ll>::lowest()/2;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ll n,m;
	cin>>n>>m;
	vector<ll> a(n);
	if(n<=5000){
		for(ll i = 0;i<n;++i){
			cin>>a[i];
		}
		ll ans = NEG_INF;
		sort(a.begin(),a.end());
		for(ll i = 0;i<n;++i){
			ll res = 1;
			ll temp = m;
			for(ll j = i-1;j>=0;--j){
				if(temp>=a[i]-a[j]){
					temp -= a[i]-a[j];
					++res;
				}else{
					break;
				}
			}
			ans = max(ans,res);
		}
		cout<<ans<<"\n";
	}else{ 
		cin>>a[0]>>a[1];
		ll diff = a[1]-a[0];
		ll l = 0,r = INF/(1<<30);
		while(l<r){
			ll mid = (l+r)/2;
			if(diff*mid*(mid-1)<=2*m){
				l = mid+1;
			}else{
				r = mid;
			}
		}
		cout<<(l-1)<<"\n";
	}
	return 0;
}
