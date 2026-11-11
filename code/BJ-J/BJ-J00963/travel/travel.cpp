#include <iostream>
#include <string>
#include <cmath>
using namespace std;
int main()
{
    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
	string c1, s1, c2, s2;
	cin >> c1 >> s1 >> c2 >> s2;
	int s1num = ((s1[0] - '0' )* 10 + (s1[1] - '0'));
	int s2num = ((s2[0] - '0' )* 10 + (s2[1] - '0'));
	bool flag[4] = {};
	if(c1 == c2)flag[0] = true;
	if(s1num == s2num)flag[1] = true;
	if(s1[2] <= 'C' && s2[2] <= 'C')flag[2] = true;
	if(s1[2] > 'C' && s2[2] > 'C')flag[2] = true;
	if(abs(s1[2] - s2[2]) == 1)
	{
		flag[3] = true;
	}
	if(s1[2] == 'D' && s2[2] == 'F' || s1[2] == 'F' && s2[2] == 'D');
	int x;
	for (int i = 0 ; i <= 3 ; i++)
	{
		if(flag[i] == true)cout << flag[i];
		else
		{
			for (i ; i <= 3 ; i++)
			{
				cout << 0;
			}
			return 0;
		}

	}
	fcloseall();
    return 0;
}
