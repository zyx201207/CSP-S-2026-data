#include <bits/stdc++.h>
using namespace std;

struct Node {
	int num;
	string s;
}a[100005];
int ans, len, n;
void huiwen(string s) {
	string ss = s;
	len = ss.size();
	if (ss == s) {
		return;
	} else {
		ans++;
		for (int i = len; i > len / 2; i++) {
			string s1 = ss;
			resever(s1.begin(), s1.end());
			
		}
		huiwen(ss);
	}
}

int main() {
	freopen ("string.in", "r", stdin);
	freopen ("string.out", "w", stdout);
	
	string ss;
	cin >> n;
	int number;
	string stringer;
	for (int i = 0, j = 0; i < n; i++) {
		cin >> number >> stringer;
		for (int k = 0; k < number; k++) ss[j++] += stringer;
	}
	huiwen(ss);
	cout << ans << endl;
	return 0;
}
