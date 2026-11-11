#include<bits/stdc++.h>
using namespace std;
long long n, e, ans, s, t, a[200000010];
char c = '1';
int main()
{
	s = 2;
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	
	cin >> n;
	for(int i = 1;i <= n;i++)
	{
		cin >> t >> c;
		a[s] = a[s] + c;
		a[t] = a[t] - c;
		s = s + t;
 	}
 	if(s % 2 == 0) e = 1;
 	else e = 0;
 	for(long long i = 1;i <= s;i++)
 	{
 		a[i] = a[i] + a[i - 1];
 		if(i > s / 2) 
 		{
 			if(a[i + 1 - e] != a[s / 2 * 2 - i + e]) ans++;
	    }
	}
	cout << ans;
	return 0;
}
