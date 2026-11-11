#include <iostream>
using namespace std;

char n[7], m[7], z[10], zu[10];
char ans[5];
int a, b, a1, b1;
int main()
{
	cin >> n >> z >> m >> zu;
	if (z[2] == 'A' || z[2] == 'B' || z[2] == 'C')
	{
		a = 1;
	}
	else
	{
		a = 2;
	}
	if (zu[2] == 'A' || zu[2] == 'B' || zu[2] == 'C')
	{
		b = 1;
	}
	else
	{
		b = 2;
	}
	if (z[2] == 'A')
	{
		a1 = 1;
	}
	else if (z[2] == 'B')
	{
		a1 = 2;
	}
	else if (z[2] = 'C')
	{
		a1 = 3;
	}
	else
	{
		a1 = 5;
	}
	if (zu[2] == 'A')
	{
		b1 = 1;
	}
	else if (zu[2] == 'B')
	{
		b1 = 2;
	}
	else if (zu[2] = 'C')
	{
		b1 = 3;
	}
	else
	{
		b1 = 5;
	}
	if (n != "01" && n != "16" && m != "01" && m != "16")
	{
		if (n[0] == m[0] && n[1] == m[1])
		{
			ans[0] = '1';
			if (z[0] == zu[0] && z[1] == zu[1])
			{
				ans[1] = '1';
				if (a == b)
				{
					ans[2] = '1';
					if (max(a1, b1) - min(a1, b1) == 1)
					{
						ans[3] = '1';
					}
					else if (a == 2 && b == 2)
					{
						ans[3] = '1';
					}
					else
					{
						ans[3] = '0';
					}
				}
				else
				{
					ans[2] = '0';
					ans[3] = '0';
				}
			}
			else
			{
				ans[1] = '0';
				ans[2] = '0';
				ans[3] = '0';
			}
		}
		else
		{
			ans[0] = '0';
			ans[1] = '0';
			ans[2] = '0';
			ans[3] = '0';
		}
	}
	else
	{
		ans[0] = '0';
		ans[1] = '0';
		ans[2] = '0';
		ans[3] = '0';
	}
	cout << ans;
	return 0;
}
