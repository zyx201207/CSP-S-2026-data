#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 7;
int n, a[N];
long long L[N], R[N];
long long ret, sum;
char s[N];
char ch;
int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i] >> s[i];
		sum += a[i];
		L[i] = sum - a[i] + 1;
		R[i] = sum;
	}
	int l = 1, r = n;
	while (l < r) {
		long long totl = sum - R[l] + 1, totr = sum - L[l] + 1;
		long long len = min(totr, R[r]) - max(totl, L[r]) + 1;
		if (s[l] != s[r]) ret += len;
		if (totl == L[r]) l++, r--;
		else if (totl < L[r]) r--;
		else l++;
	}
	cout << ret;
	return 0;
}
