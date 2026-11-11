#include <bits/stdc++.h>
using namespace std;
long long a,n;
char c;
string s,s1;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%lld",&n);
	for (int i = 0; i < n; i++)
	{
		cin >> a >> c;
		for (long long j = 0; j < a; j++)
		    s += c;
	}
	for (long long i = 0, j = s.length(); i < s.length(); i++,j--)
		s1[i] = s[j];
	long long ans = 0;
	for (long long i = 0; i < min(s.size(), s1.size()); i++)
	    if (s[i] != s1[i]) ans++;
	cout << ans;
	return 0;
}
