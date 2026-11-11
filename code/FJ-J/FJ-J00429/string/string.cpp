#include <bits/stdc++.h>
using namespace std;

struct strs
{
	long long t;
	char c;
} lst[200005];

int main()
{
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	int n;
	cin >> n;
	for(int i=1 ; i<=n ; i++)
	{
		cin >> lst[i].t >> lst[i].c;
	}
	long long ans = 0, l = 1, r = n;
	while(l != r) 
	{
		if(lst[l].c != lst[r].c)
		{
			if(lst[l].t <= lst[r].t)
			{
				ans += lst[l].t;
				lst[r].t -= lst[l].t;
				l++;
			}
			else
			{
				ans += lst[r].t;
				lst[l].t -= lst[r].t;
				r--;
			}
		}
		else if(lst[l].t != lst[r].t)
		{
			if(lst[l].t <= lst[r].t)
			{
				lst[r].t -= lst[l].t;
				l++;
			}
			else
			{
				lst[l].t -= lst[r].t;
				r--;
			}
		}
	}
	cout << ans;
	return 0;
}
