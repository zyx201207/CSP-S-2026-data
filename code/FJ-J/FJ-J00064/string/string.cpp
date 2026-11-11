#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstdio>
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>
#include <iterator>
#include <cmath>
using namespace std;
using ll = long long;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ll n;
	cin>>n;
	string s;
	for(ll i = 0;i<n;++i){
		ll a;
		char c;
		cin>>a>>c;
		for(ll j = 0;j<a;++j){
			s += c;
		}
	}
	ll ans = 0;
	n = s.size();
	for(ll i = 0;i<n/2;++i){
		if(s[i]!=s[n-i-1]){
			++ans;
		}
	}
	cout<<ans<<"\n";
	return 0;
}
