#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
int a[N];
char c[N];
string s;
int main()
{
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	long long sum = 0;
	cin >> n;
	for (int i = 1; i <= n; i++) 
	{
		cin >> a[i] >> c[i];
		sum += a[i];
		if (a[i] <= 500) for (int j = 1; j <= a[i]; j++) s += c[i]; 
	}
	if (sum > 1e9) cout << sum / 2;
	else
	{
		int l = s.size();
		s = " " + s;
		int mid = 1+l>>1, cnt = 0;
		for (int i = 1; i <= mid; i++)
			if (s[i] != s[l+1-i]) cnt++;
		cout << cnt;
	}
	return 0;
}
