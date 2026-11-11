#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll a[200005];
char c[26];
int main()
{
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	int n;
	cin >> n;
	string s = "";
	for (int i=1;i<=n;i++)
	{
		cin >> a[i] >> c[i];
		for (int j=1;j<=a[i];j++) s += c[i];
	}
	int ans = 0;
	for (int i=1;i<=s.length()/2;i++)
	{
		for (int j=n;j>=s.length()/2;j--)
		{
			if (s[i] != s[j])
			{
				ans++;
			}
		}
	}
	cout << ans;
	return 0;
}
