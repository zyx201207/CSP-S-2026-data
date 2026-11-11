#include <bits/stdc++.h>
using namespace std;

int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	string a = "";
	long long n,b;
	cin >> n;
	char c;
	for (int i = 1; i <= n; i++)
	{
		cin >> b >> c;
		for (int j = 1; j <= b; j++)
		{
			a += c;
		}
	}
	long long num = 0;
	for (int i = 0; i < a.length() / 2; i++)
	{
		if (a[i] != a[a.length() - i - 1])
		{
			num++;
		}
	}
	cout << num;
	return 0;
}
