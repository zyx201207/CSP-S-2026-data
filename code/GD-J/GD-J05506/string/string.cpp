# include <bits/stdc++.h>
using namespace std;

int ans, n, a[200005], aall, aisum;
char c[200005];
int main(){
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin >> n;
	for (int i = 0; i <= n; i++){
		cin >> a[i] >> c[i];
		aall += a[i];
	}
	char alla[aall];
	for (int i = 0; i < aall; i++) alla[i] = 0;
	for (int i = 0; i <= n; i++){
		if (i == 0) aisum = 0;
		for (int j = aisum; j < aisum + a[i]; j++){
			alla[j] = a[i];
		}
	}
	for (int i = 0; i < aall / 2; i++){
		if (alla[i] != alla[aall - i]) ans++;
	}
	cout << ans;
	return 0;
}
