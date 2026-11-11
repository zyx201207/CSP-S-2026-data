#include <bits/stdc++.h>
using namespace std;
const int N = 2e5;
int n, a[N], ans, cnt;
string c[N], s;
int main(){
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout); 
	scanf("%d", &n);
	for (int i = 1; i <= n; i++){
		cin >> a[i] >> c[i];
	}
	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= a[i]; j++){
			s += c[i];
			cnt++;
		}
	}
	for (int i = 1; i <= cnt / 2; i++){
		if (s[i] != s[cnt - i + 1]) ans++;
	}
	cout << ans;
    return 0;
}
