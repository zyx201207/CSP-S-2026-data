#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
int a[N];
char c[N];
int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	int n;
	cin >> n;
	string s = "";
	for(int i = 1; i <= n; i++)
	{
		cin >> a[i] >> c[i];
		for(int j = 1; j <= a[i]; j++)
			s += c[i];
	}
	int ans = 0;
	for(int i = 0, j = s.size() - 1; i <= j; i++, j--)
		if(s[i] != s[j])
			ans += 1;
	cout << ans << endl;
	return 0;
}
