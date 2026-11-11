#include <bits/stdc++.h>
#define ll long long
using namespace std;
int n,a[200005],ans;
char c[200005];
string s;
int len;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	for (int i = 1;i <= n;i++)
	{
		cin >> a[i] >> c[i];
		len += a[i];
		for (int j = 1;j <= a[i];j++)
		{
			s += c[i];
		}
	}
	s = " " + s;
	int mid = len / 2;
	for (int i = 1;i <= mid;i++)
	{
		if (s[i] != s[len - i + 1])
		{
			ans++;
		}
	}
	cout << ans;
	return 0;
}
