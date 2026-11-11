#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;
long long ans = 0, a[N]; char c[N];

int main()
{	
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
		
	int n;
	cin >> n;
	for (int i = 1; i <= n; i ++) cin >> a[i] >> c[i];
	
	int l = 1, r = n;
	while (l <= r)
	{
		if (c[l] != c[r]) 
		{
			if (a[l] < a[r])
			{
				ans += a[l];
				a[r] -= a[l];
				l ++;
			}
			else if (a[l] == a[r])
			{
				ans += a[l];
				l ++, r --;
			}
			else 
			{
				ans += a[r];
				a[l] -= a[r];
				r --;
			}
		}
		else
		{
			if (a[l] < a[r]) 
			{
				a[r] -= a[l];	
				l ++;
			}
			else if (a[l] == a[r]) l ++, r --;
			else 
			{
				a[l] -= a[r];
				r --;
			}	
		}
	}
	cout << ans << "\n";
	return 0;
}  
