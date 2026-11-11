#include <bits/stdc++.h>
using ll = long long;
using namespace std;
#define cin fin
#define cout fout
ifstream fin("and.in");
ofstream fout("and.out");
int main(){
	ll n,m;
	cin >> n >> m;
	vector<ll> a(n);
	for(ll i = 0;i < n;i++){
		cin >> a[i];
	}
	if(m==1){
		ll maxnum = -1;
		sort(a.begin(),a.end())
		cout << a[a.size()-1];
		return 0;
		
	}
	if(m==n){
		ll ans = a[0]&a[1];
		for(ll i = 2;i < n;i++){
			ans=ans&a[i];
		}
		cout << ans;
		return 0;
	}
	if(m==n-1){
		vector<ll> ans
		for(ll i = 1;i < n;i++){
			ll num = a[0];
			for(ll j = 1;j < n;j++){
				if(a[j]==a[i])continue;
				num&=a[j];
			}
			ans.push_back(num);
		}
		ll num = a[1];
		for(ll i = 2;i < n;i++){
			num&=a[i];
		}
		ans.push_back(num);
		sort(ans.begin(),ans.end());
		cout << ans[ans.size()-1];
		return 0;
	}
	if(m==2){
		vector<ll> ans; 
		for(ll i = 0;i < n;i++){
			ll num = a[i];
			for(ll j = 0;j < n;j++){
				if(a[j]==a[i])continue;
				num&=a[j];
				ans.push_back(num);
			}
		}
		sort(ans.begin(),ans.end());
		cout << ans[ans.size()-1];
		return 0;
	}
	
	return 0;
	
}
