#include <bits/stdc++.h>
using namespace std;
int n, length = 0;
char c[100001];
const int N = 100000;
long long a[100001], ans = 0;
bool big = false;
vector<char> s;
void pingjie() {
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= a[i]; j++) {
			s.push_back(c[i]);
			length++;
		}
	}
}
int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin >> n;
	for(int i = 1; i <= n; i++) {
		cin >> a[i] >> c[i];
		if(a[i] >= N) {
			big = true;
			a[i] /= N;
		}
	}
	pingjie();
	int l = 0, r = length-1; 
	while(l <= r) {
		if(s[l] != s[r]) {
			ans++;
		}
		l++; r--;
	}
	if(big) cout << ans * N;
	else cout << ans;
	return 0;
}
