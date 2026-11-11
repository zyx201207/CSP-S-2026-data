#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 5e5 + 5;
ll n, m, a[N], sum[N], maxn;
int main(){
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1; i <= n; ++i) cin >> a[i];
	sort(a + 1, a + n + 1);
	for(int i = 1; i <= n; ++i) sum[i] = sum[i - 1] + a[i];
	for(int i = 1; i <= n; ++i){
		ll len = (m + sum[i - 1]) / a[i];
		if(len >= i) continue;
		maxn = max(maxn, len + 1);
	}		
	cout << maxn;
	return 0;
}
