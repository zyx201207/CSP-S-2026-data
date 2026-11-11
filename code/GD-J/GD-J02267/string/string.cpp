#include <bits/stdc++.h>
using namespace std;

long long n,a[200010];
char s[200010];

int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	for(int i = 1; i <= n; i++)
	{
		cin >> a[i] >> s[i];
	}
	long long b = 0;
	long long l = 1,r = n;
	while(r>=l)
	{
		if(s[l] == s[r])
		{
			if(a[l] > a[r])
			{
				a[l] -= a[r];
				a[r] = 0;
				r--;
			}
			else if(a[l] < a[r])
			{
				a[r] -= a[l];
				a[l] = 0;
				l++;
			}
			else
			{
				a[l] = 0;
				a[r] = 0;
				l++;
				r--;
			}
		} 
		
		else
		{
			b += min(a[l],a[r]);
			if(a[l] > a[r])
			{
				a[l] -= a[r];
				a[r] = 0;
				r--;
			}
			else if(a[l] < a[r])
			{
				a[r] -= a[l];
				a[l] = 0;
				l++;
			}
			else
			{
				a[l] = 0;
				a[r] = 0;
				l++;
				r--;
			}
		}
	}
	cout << b;
	return 0;
} 
