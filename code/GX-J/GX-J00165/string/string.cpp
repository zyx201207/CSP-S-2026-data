#include <bits/stdc++.h>
using namespace std;

struct stu
{
	long long number;
	char s;
}a[200005];
long long n;

int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	long long j = 1;
	for(int i = 1; i <= n; i++)
	{
		long long t;
		char b;
		cin >> t >> b;
		if(i == 1)
		{
			a[j].number = t;
			a[j].s = b;
		}
		else if(a[j].s == b)
		{
			a[j].number += t;
		}
		else
		{
			j++;
			a[j].number += t;
			a[j].s = b;
		}
	}
	long long l = 1,r = j,ans = 0;
	while(l <= r)
	{
		if(a[l].s != a[r].s)
		{
			ans += min(a[l].number,a[r].number);
		}
		if(a[l].number < a[r].number)
		{
			a[r].number -= a[l].number;
			l++;
		}
		else if(a[l].number > a[r].number)
		{
			a[l].number -= a[r].number;
			r--;
		}
		else
		{
			l++;
			r--;
		}
	}
	cout << ans;
	return 0;
}
