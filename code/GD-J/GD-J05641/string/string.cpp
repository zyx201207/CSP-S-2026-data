#include <bits/stdc++.h>
using namespace std;
struct un
{
	long long num;
	char nam;
}a[200005];
long long ans;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n;
	cin >> n;
	for (int i = 1;i <= n;i++)
	{
		cin >> a[i].num >> a[i].nam;
		ans += a[i].num;
	}
	if (n == 1)
	{
		cout << '0';
		return 0;
	}
	long long mid = ans / 2;
	long long l = 1,r = n,lr = 0,rr = 0;
	ans /= 2; 
	while(l < r)
	{
		lr = lr == 0 ? a[l].num : lr;
		rr = rr == 0 ? a[r].num : rr; 
		if (a[l].nam == a[r].nam)
		{
			if (lr < rr)
			{
				rr -= lr;
				ans -= lr;
				lr = 0;
				l++;
			}
			else if (lr > rr)
			{
				lr -= rr;
				ans -= rr;
				rr = 0;
				r--;
			}
			else
			{
				lr = 0;
				rr = 0;
				ans -= lr;
				l++;
				r--;
			}
		}
		else
		{
			if (lr < rr) 
			{
				rr -= lr;
				lr = 0;
				l++;
			}
			else if (lr > rr)
			{
				lr -= rr;
				rr = 0;
				r--;
			}
			else
			{
				lr = 0;
				rr = 0;
				l++;
				r--;
			}
		}
	}
	if (a[l].num - rr - lr > 1 && l == r)
	{
		ans -= a[l].num / 2;
	}
	cout << ans;
	return 0; 
}
