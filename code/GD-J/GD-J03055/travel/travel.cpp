#include <bits/stdc++.h>
using namespace std;

char ans[4];

int main()
{
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	string rc, rs, xc, xs;
	cin >> rc >> rs >> xc >> xs;
	if(rc == xc)
	{
		ans[0] = '1';
		if(rs.substr(0, 2) == xs.substr(0, 2))
		{
			ans[1] = '1';
			if((rs[2] == 'A' || rs[2] == 'B' || rs[2] =='C') && (xs[2] == 'A' || xs[2] == 'B' || xs[2] == 'C') || (rs[2] == 'E' || rs[2] == 'F') && (xs[2] == 'E' || xs[2] == 'F'))
			{
				ans[2] = '1';
				if(rs[2] == 'A' && xs[2] == 'B' || rs[2] == 'B' && xs[2] == 'C' || rs[2] == 'E' && xs[2] == 'C') ans[3] = '1';
				else ans[3] = '0';
			} 
			else ans[2] = '0', ans[3] = '0';
		} 
		else ans[1] = '0', ans[2] = '0', ans[3] = '0';
	}
	else ans[0] = '0', ans[1] = '0', ans[2] = '0', ans[3] = '0';
	for(int i = 0; i < 4; i++) cout << ans[i];
	return 0;
}
