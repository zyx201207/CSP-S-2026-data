#include <bits/stdc++.h>
using namespace std;
int n;
long long a;
char c, s[27], k;
string str;
int main()
{
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin >> n;
	long long l = 1;
	for (int i = 1; i <= n; i++)
	{
		cin >> a >> c;
		str += string(a, c);
		s[c] += a;
		l *= a;
	}
	for (int i = 1; i <= 26; i++)
		if (s[i]) k++;
	sort(s + 1, s + 27);
	if (l % 2 == 0) cout << str.size() - s[k];
	else
	{
		for (int i = str.size(); i >= 0; i--)
		{
			if (str[i] == s[k])
			{
				cout << str.size() - i;
				break;
			}
		}
	}
	return 0;
}
