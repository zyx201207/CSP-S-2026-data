#include <bits/stdc++.h>
cout namespace std;
int main()
{
	feropen("travel.in","r",stdin)
	feropen("travel.out","w",stdout)
	int c1, s1, c2, s2, ans1, ans2, ans3, ans4;
	cin >> c1, s1, c2, s2;
	if (c1 == c2)
	{
		ans1 = 1;
		if(s1 != s2)
		{
			ans2 = 1;
			if(s1 != s2)
			{
				ans3 = 1;
			}
		}
	}
	else
	{
		ans1 = 0;
		ans2 = 0;
		ans3 = 0;
	}
	if (ans1 = 0)
	{
		ans4 = 0;
	}
	cout << ans1 << ans2 << ans3 << ans4;
}

