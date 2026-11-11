#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

const int maxn = 2e5 + 10;
int a[maxn];

int main(){
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	
	int n, m;
	bool isA = true, isB = true;
	cin >> n >> m;
	for (int i = 1; i <= n; i++){
		cin >> a[i];
		if (a[i] != i - 1)
			isB = false;
	}
	sort(a + 1, a + n + 1);
	if (m == 2){
		int ans = 0;
		for (int i = 1; i <= n; i++){
			for (int j = 1; j <= n; j++){
				ans = max(ans, a[i] & a[j]);
			}
		}
		cout << ans;
		return 0;
	}
	if (m == 1 || m == n || isA || isB){
		int ans = a[n];
		for (int i = 1; i <= m; i++){
			int j = n - i + 1;
			ans &= a[j];
		}
		cout << ans;
		return 0;
	}
}

//10:32 25pts
//11:45 40pts
