#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
int n, m;
int h[N];
bool cmp(int a, int b){
	return a > b;
}
int main(){
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++){
		cin >> h[i];
	}
	sort(h + 1, h + n + 1, cmp);
	long long ans = 0;
	for (int i = 1; i <= m; i++){
		h[i + 1] &= h[i];
		ans = h[i + 1];
	}
	cout << ans;
	return 0;
} 
