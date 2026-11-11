#include <bits/stdc++.h>
using namespace std;
int n;
int a;
char c;
string s;
long long sum;


int main ()
{
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	scanf("%d", &n);
	for (int i = 1;i <= n;i++)
	{
		cin >> a >> c;
		for (int j = 1;j <= a;j++)
			s += c;
	}
	long long len = s.size();
	for (int i = 0;i < len / 2;i++)
		if (s[i] != s[len - i - 1])
			sum++;
	cout << sum;
	return 0;
}
