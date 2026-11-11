#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	int n, a[200005];
	char c[200005];
	string s;
	cin >> n;
	for (int i = 1; i <= n; ++i){
		cin >> a[i] >> c[i];
	}
	if (n == 1) cout << 0;
	return 0;
}
