#include<bits/stdc++.h>
using namespace std;
long long n, a[200005], ans;
char b[200005];
int main()
{
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin >> n;
	for(int i = 1; i <= n; i++) cin >> a[i] >> b[i];
	for(int i = 1, j = n; i < j;)
	{
		if(a[i] == a[j])
		{
			if(b[i] == b[j])
			{
				i ++, j --;
			}
			else
			{
				ans += a[i];
				i ++, j --;
			}
		}
		if(a[i] > a[j])
		{
			if(b[i] == b[j]) 
			{
				a[i] -= a[j];
				j--;
			}
			else
			{
				a[i] -= a[j];
				ans += a[j];
				j--;
			}
		}
		if(a[i] < a[j])
		{
			if(b[i] == b[j]) 
			{
				a[j] -= a[i];
				i++;
			}
			else
			{
				a[j] -= a[i];
				ans += a[i];
				i++;
			}
		}
	}
	cout << ans;
	return 0;
}
