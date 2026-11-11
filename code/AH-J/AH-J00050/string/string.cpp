#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	ll n,ans=0;
	string all;
	cin >> n;
	vector<ll> a(n);
	vector<char> c(n);
	for(int i=0;i<n;i++){
		cin >> a[i] >> c[i];
		string tmp(a[i],c[i]);
		all+=tmp;
	}
	ll l=0,r=all.size()-1;
	while(true){
		if(all[r]!=all[l]){
			ans++;
		}
		r--;
		l++;
		if(r==l) break;
		if(r<l) break;
	}
	cout << ans;
	//cout << all;
	return 0;
}
