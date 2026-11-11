#include <bits/stdc++.h> 
using namespace std;
string s1;
string s2;
string sa;
string ss;
bool zt[8];
int main()
{
	freopen("travel.in","r",stdin);freopen("travel.out","w",stdout);
	cin >> s1 >> s2 >> sa >> ss;
	if(s1 == sa)
	{
		zt[1] = 1;
		if(s2[0] == ss[0] && s2[1] == ss[1])
		{
			zt[2] = 1;
			if((s2[2] <= 'C' && s2[2] >= 'A' && ss[2] <= 'C' && ss[2] >= 'A') || (s2[2] <= 'F' && s2[2] >= 'D' && ss[2] <= 'F' && ss[2] >= 'D'))
			{
				zt[3] = 1;
				if((abs(s2[2] - ss[2]) == 1) || (s2[2] == 'D' && ss[2] == 'F') || (s2[2] == 'F' && ss[2] == 'D'))
				{
					zt[4] = 1;
				}
			}
		}
	}
	for(int f = 1; f <= 4; f++)
		cout << zt[f];
	return 0;
}
