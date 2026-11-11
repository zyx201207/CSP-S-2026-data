#include<bits/stdc++.h>

using namespace std;
const int N = 2e5 + 10;

int a[N];
char s[N];
int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	
	int n;
	cin >> n;
	long long sum = 0;
	string c1, c2;
	for (int i = 1; i <= n; i++) {
		cin >> a[i] >> s[i];
		sum += a[i];
		for (int j = 1; j <= a[i]; j++) {
			c1 += s[i];
		}
	}
	int n2 = c1.size();
	for (int i = n2 - 1; i >= (n2 + 1) / 2; i--) c2 += c1[i];
	long long cnt = 0;
	for (int i = 0; i < n2 / 2; i++) {
		if (c1[i] != c2[i]) cnt++;
	}
	cout << cnt; 
	
	return 0;
	
} 
