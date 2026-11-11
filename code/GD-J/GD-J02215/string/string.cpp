#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
long long n, a[N], sum[N];
long long ans;
char c[N];
string s;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	for(int i = 1; i <= n; i++)
	{
		cin >> a[i] >> c[i];
		sum[i] = sum[i - 1] + a[i];
		for(int j = 1; j <= a[i]; j++)
		{
			s += c[i];
		}
	}
	long long l = s.length();
	for(long long i = 0; i < s.length() / 2; i++)
	{
		if(s[i] != s[l - 1 - i])
			ans++;
	}
	cout << ans;


}
