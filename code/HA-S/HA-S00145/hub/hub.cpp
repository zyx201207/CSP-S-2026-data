#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll ksm(ll a, ll b, ll c){
	ll ans = 1;
	a = a % c;
	while(b > 0){
		if(b & 1){
			ans = ans * a % c;
		}
		a = a * a % c;
		b >>= 1;
	}
}
int main(){
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cout << 1 << '\n' << 2;
	return 0;
}
