#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 1;
long long n, m, a[N], ans= 0;
char c[27];
string s;
int main()
{
	//freopen("string", "r", stdin);
	//freopen("string", "w", stdout);
	cin >> n;
	for (int i = 1; i <= n; i++) 
	{	
		cin >> a[i] >> c[i];
		if (n == 1 || c[i] == c[i + 1])
		{
			cout << 0;
			return 0;
		}
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= a[i]; j++)
		{
			s += c[i];
		}
	}
	for (int i = 1; i <= n; i++)
	{
		if(s[i] = s[i + 1]) ans++;
	}
	cout << s.size() - ans;
	return 0;
}
