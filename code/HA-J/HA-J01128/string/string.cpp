#include <bits/stdc++.h>
using namespace std;

long long n, sum, cnt;
long long a[200010];
char c[200010];
string s;

int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i] >> c[i];
		sum += a[i];
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= a[i]; j++)
		{
			s += c[i];
		}
	}
	int i = 0, j = sum;
	while (i <= j)
	{
		if ( s[i] != a[j] )
		{
			if ( s[i+1] == s[i] )
			{
				s[j] = s[i];
				cnt++;
			}
			else if ( s[j-1] == s[j] )
			{
				s[i] = s[j];
				cnt++;
			}
		}
		i++;
		j++;
	}
	cout << cnt;
	
	return 0;
}
