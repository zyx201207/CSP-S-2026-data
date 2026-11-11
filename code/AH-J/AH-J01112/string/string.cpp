#include <bits/stdc++.h>
using namespace std;


long long cnt = 0;

int main()
{
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	unsigned long long n;
	cin >> n;
	unsigned long long a[n];
	char c[n];
	for (unsigned long long i = 0; i < n; i++) cin >> a[i] >> c[i];
	unsigned long long sz = accumulate(a, a+n, 0); //sz = s.size();
	char s[sz];
	for (unsigned long long i = 0; i < n; i++)
	{
		for (unsigned long long j = 0; j < a[i]; j++) s[i*a[i]+j] = c[i];
	}
	int flag = 1;
	for (unsigned long long i = 0; i < sz/2; i++)
	{			
		if (s[i]!=s[sz-i-1])
		{
			flag = 0;
			break;
		}
	}
	if (flag==1)
	{
		cout << 0;
	}
	else
	{
		for (unsigned long long i = 0; i < sz/2; i++)
		{
			if (s[i] != s[sz-1-i]) cnt++;
		}
		cout << cnt;
	}
	return 0;
}
