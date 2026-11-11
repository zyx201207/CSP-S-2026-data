#include <bits/stdc++.h>
using namespace std;
int n;
long long a[200100];
char c[200100];
long long ans;

int main()
{
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> a[i] >> c[i];
	int left = 1;
		int right = n;
	while(left <= right)
	{
		if (c[left] != c[right])
		{
			if (a[left] < a[right])
			{
				ans += a[left];
				a[right] -= a[left];
				left++;
			}
			else if (a[left > a[right]])
			{
				ans += a[right];
				a[left] -= a[right];
				right--;
			}
			else
			{
				ans += a[left];
				left++;
				right--;
			}
		}
		else if(c[left] == c[right])
		{
			if (a[left] < a[right])
			{
				a[right] -= a[left];
				left++;
			}
			else if (a[left > a[right]])
			{
				a[left] -= a[right];
				right--;
			}
			else
			{
				left++;
				right--;
			}
			
		}
	}
	cout << ans;
	return 0;
}
