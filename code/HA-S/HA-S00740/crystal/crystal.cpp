#include <bits/stdc++.h>
#define ll long long 

using namespace std;
const int N = 5e5+5; 
int n; 
ll m, a[N]; 

int main () {
	freopen("crystal.in", "r", stdin); 
	freopen("crystal.out", "w", stdout); 
	ios::sync_with_stdio(0); 
	cin.tie(0); cout.tie(0); 
	cin >> n >> m; 
	for (int i = 1;i <= n;i++) cin >> a[i]; 
	sort(a+1, a+1+n); 
	int ans = 0; ll sm = 0; 
	for (int i = 1, j = 1;i <= n;i++) {
		while (sm+(i-j)*(a[i]-a[i-1]) > m) sm -= (a[i-1]-a[j]), j++; 
		sm += (i-j)*(a[i]-a[i-1]); ans = max(ans, i-j+1); 
	}
	cout << ans; 
	return 0; 
}
/*
crystallized 
*/
