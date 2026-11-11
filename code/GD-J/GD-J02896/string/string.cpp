#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[200005];
string b[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ll n;
	ll c;
	cin >> n;
	for(ll i =0; i<n;i++){
		cin >> a[i];
		cin >> b[i];
	}
	for(ll i=0; i<n; i++){
		c += a[i];
	}
	c= c/2;
	cout << c;
	return 0;
}
 
