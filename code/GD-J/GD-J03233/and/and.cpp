#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

const int N = 2e5+10;
int n, m, a[N], ans = 0, cnt[105];

int main(){
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n >> m;
	for (int i = 1; i <= n; i++){
		cin >> a[i];
	}
	for (int j = 29; j >= 0; j--){
		for (int i = 1; i <= n; i++){
			if (((a[i]>>j) & 1) && ((ans & a[i]) == ans)) cnt[j]++; 
		}
		if (cnt[j] >= m){
			ans = (ans | (1<<j));
		}
	}
	cout << ans;
	return 0;
}
