#include <bits/stdc++.h>
using namespace std;
int n;
long long ans;
long long a[200005];
char c[200005];
long long s[200005] , j[200005];
int main()
{
	freopen("string.in" , "r" , stdin);
	freopen("string.out" , "w" , stdout);
	cin >> n;
	for(int i = 1; i <= n; i++)
	{
		cin >> a[i] >> c[i];
		s[i] = s[i - 1] + a[i];
	}
	c[0] = c[1];
	long long l = s[n];
	int num = upper_bound(s + 1 , s + n + 1 , (l + 1) / 2) - s;
	for(int i = 1; i < num; i++) j[i] = s[i];
	for(int i = num; i <= n; i++) j[i] = l + 1 - s[i];
	sort(j + 1 , j + n + 1);
	for(int i = 1; i <= n; i++)
	{
		int pos1 = upper_bound(s + 1 , s + n + 1 , j[i]) - s - n % 2;
		int pos2 = upper_bound(s + 1 , s + n + 1 , l + 1 - j[i]) - s - 1;
		if(c[pos1] != c[pos2]) 
		{
			ans += j[i] - j[i - 1];
		}
	}
	cout << ans;
	return 0;
}
