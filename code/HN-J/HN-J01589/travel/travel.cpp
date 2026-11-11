#include <bits/stdc++.h>

using namespace std;

int ans[10] = {};
string ca, sa, cb, sb;

int main ()
{
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	cin >> ca >> sa >> cb >> sb;
	if (ca == cb)
	{
		ans[1] = 1;
		if (sa[0] == sb[0] && sa[1] == sb[1])
		{
			ans[2] = 1;
			if ((sa[2] == 'A' || sa[2] == 'B' || sa[2] == 'C') && (sb[2] == 'A' || sb[2] == 'B' || sb[2] == 'C'))
			{
				ans[3] = 1;
				if (abs(sa[2] - sb[2]) == 1)
				{
					ans[4] = 1;
				}
			}
			else if ((sa[2] == 'D' || sa[2] == 'F') && (sb[2] == 'D' && sb[2] == 'F'))
			{
				ans[3] = 1, ans[4] = 1;
			}
		}
	}
	cout << ans[1] << ans[2] << ans[3] << ans[4] << "\n";
	return 0;
}
