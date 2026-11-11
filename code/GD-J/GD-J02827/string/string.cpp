#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 9;
int n, a[N], sum, cnt;
char c[N], m[15000000];

int main(){
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin >> n;
	for (int i = 1; i <= n; i++){
		cin >> a[i] >> c[i];
		for (int j = sum + 1; j <= sum + a[i]; j++) m[j] = c[i];
		sum += a[i];
	}
	for (int i = 1, j = sum; i < j; i++, j--){
		if (m[i] != m[j]) cnt++;
	}
	cout << cnt;
	return 0;
}
