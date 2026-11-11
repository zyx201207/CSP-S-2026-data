#include <bits/stdc++.h>

using namespace std;

int n;
const int maxn = 2e5 + 1;
int a[maxn];
char c[maxn];
long long pre[maxn];
int S1[27], S2[27];
int convert(char c) {
	return int(c - 97);
}
long long ans;
long long half_index;
int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i] >> c[i];
		pre[i] = pre[i - 1] + a[i];
	}
	half_index = pre[n] >> 1;
	cout << half_index << endl;
	for (int i = 1; i <= n; i++) {
		if (pre[i] <= half_index) {
			S1[convert(c[i])] += a[i];
			cout << "mode 1" << a[i] << endl;
		} else if (pre[i - 1] >= half_index) {
			S2[convert(c[i])] += a[i];
			cout << "mode 2" << a[i] << endl;
		} else {
			S1[convert(c[i])] += half_index - pre[i - 1];
			S2[convert(c[i])] += pre[i] - half_index;
			cout << "mode 3" << a[i] << endl;
		}
	}
	
	if (pre[n] % 2 == 1) {
		half_index++;
		S2[convert(c[half_index])]--;
	}
	for (int i = 0; i < 26; i++) {
		cout << (char)(i + 97) << " " << abs(S1[i] - S2[i]) << endl;
		ans += abs(S1[i] - S2[i]);
	}
	cout << half_index << endl;
	cout << ans << endl;
}
