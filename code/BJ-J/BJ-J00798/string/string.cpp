#include<bits/stdc++.h>
using namespace std;
int n;
long long a[200005];
char s[200005];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long ans = 0;
	cin >> n;
	for(int i = 1;i <= n;i++)
	{
		cin >> a[i] >> s[i];
	}
	for(int i = 1,j = n;i <= n&&j > i;)
	{
		if(s[i] != s[j])
		{
			if(a[i] > a[j])
			{
				ans += a[j];
				a[i] -= a[j];
				j--;
			}
			else if(a[i] < a[j])
			{
				ans += a[i];
				a[j] -= a[i];
				i++;
			}
			else
			{
				ans += (a[i] + a[j]) / 2;
				i++;
				j--;
			}
		}
		else 
		{
			if(a[i] > a[j])
			{
				a[i] -= a[j];
				j--;
			}
			else if(a[i] < a[j])
			{
				a[j] -= a[i];
				i++;
			}
			else
			{
				i++;
				j--;
			}
		}
	}
	cout << ans;
	return 0;
}
