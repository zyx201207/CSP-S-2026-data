#include <iostream>
#include <string>
using namespace std;
string c1,c2,c3,c4;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int ans1 = 0,ans2 = 0,ans3 = 0,ans4 = 0,seat1 = 0,seat2 = 0;
	cin >> c1 >> c2 >> c3 >> c4;
	seat1 = (int(c1[1]) - 48) + (int(c1[0]) - 48) * 10;
	seat2 = (int(c3[1]) - 48) + (int(c3[0]) - 48) * 10;
	if (seat1 != seat2)
	{
		ans1 = 0;
	}
	else
	{
		ans1 = 1;
	}
	bool flag = false;
	for (int i = 0;i <= 1;i++)
	{
		if (c2[i] != c4[i])
		{
			flag = true;
			break;
		}
	}
	if (!flag)
	{
		ans2 = 1;
	}
	if (c2[2] == 'A' || c2[2] == 'B' || c2[2] == 'C')
	{
		if (c4[2] == 'A' || c4[2] == 'B' || c4[2] == 'C')
		{
			ans3 = 1;
		}
	}
	else
	{
		if (c4[2] == 'F' || c4[2] =='D')
		{
			ans3 = 1;
		}
	}
	if (ans3 != 0)
	{
		if ((c2[2] == 'D' && c4[2] == 'F') || (c2[2] == 'F' && c4[2] == 'D'))
		{
			ans4 = 1;
		}
		else if (c4[2] == char(int(c2[2]) + 1) || c4[2] == char(int(c2[2]) - 1))
		{
			ans4 = 1;
		}
	}
	if (ans1 == 0)
	{
		ans2 = ans3 = ans4 = 0;
	}
	else if (ans2 == 0)
	{
		ans3 = ans4 = 0;
	}
	cout << ans1 << ans2 << ans3 << ans4;
	return 0;
} 
