#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	string ans = "A";
	ll sum = 0;
	for(ll i = 1;i<=n;i++){
		ll a;string b;
		cin >> a >> b;
		sum+=a;
		for(ll j = 1;j<=a;j++){
			ans = ans+b;
		}
	}
	ll cnt = 0;
	for(ll i = 1;i<=sum/2;i++){
		if(ans[i]!=ans[sum-i+1]){
			cnt++;
		}
	}
	cout << cnt;
	return 0;
}
