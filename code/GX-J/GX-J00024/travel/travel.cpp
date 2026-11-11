#include <bits/c++.h>
namespace std;
int main()
{
	chr c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	if (ci == c2)
	{
		if (s1[0] == s2[0])
		{
			if(s1[1] == s2[1])
			{
				if (s1[2] <= "C")
				{
					if (s2[2] <= "C")
					{
						if (s1[2] == "B")
						{
							cout<<"1111";
						}
						else
						{
							if (s2[2] == "B")
							{
								cout<<"1111";
							}
							else
							{
								cout<<"1110";
							}
						}
					}
					else
					{
						cout<<"1100";
					}
				}
				else
				{
					if (s2[2] > "C")
					{
						cout<<"1111";
					}
					else
					{
						cout<<"1100";
					}
				}
			}
			else
			{
				cout<<"1000";
			}
		}
		else
		{
			cout<<"1000";
		}
	}
	else
	{
		cout<<"0000";
	}
	return 0;
}
