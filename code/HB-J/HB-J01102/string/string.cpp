#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n, num, l = 0, ans = 0;
	string s;
	char c;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> num >> c;
		l = l + num - 1;
		for (int j = 1; j <= num; j++)
			s = s + c;
	}
	for (int i = 0; i < l / 2 + 1; i++)
		if (s[i] != s[l + 1 - i])
			ans++;
	cout << ans << endl;
	return 0;
}
