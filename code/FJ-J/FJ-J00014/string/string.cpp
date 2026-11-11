#include <bits/stdc++.h>
using namespace std;

int main()
{
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	string s1 = "";
	long long n, ans = 0;
	cin >> n;
	if(n == 1) {
		cout << 0;
		return 0;
	}
	for(int i = 1; i <= n; i++)
	{
		int k;
		char c;
		cin >> k >> c;
		for(int j = 1; j <= k; j++) {
			s1 += c;
		}
	}
	for(int l = 0, r = s1.size() - 1; l <= r; l++, r--) {
		if(s1[l] != s1[r]) cout << l << " " << r << endl, ans++;
	}
	cout << ans;
	return 0;
}
