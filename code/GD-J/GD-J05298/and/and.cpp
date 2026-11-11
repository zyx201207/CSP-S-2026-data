#include<bits/stdc++.h>
#define ll long long
using namespace std;

const int N = 2e5 + 10; 
ll a[N];
bool cmp(ll x, ll y){
	return x > y; 
}
int main(){
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	
	int n, m;
	cin >> n >> m;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
	}
	stable_sort(a + 1, a + 1 + n, cmp);
	ll ans = a[1];
	for(int i = 1; i <= m; i++){
		ans = (ans & a[i]);
	}
	cout << ans;
	return 0;
}
