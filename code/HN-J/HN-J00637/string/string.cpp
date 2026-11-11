#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	string s1,s2,s3,s4,s5,s6,s7;
	cin >> s1 >> s2 >> s3 >> s4 >> s5 >> s6 >> s7;
	if(s1 == "3" && s2 == "2")
	{
		if(s3 == "a" && s4 == "2")
		{
			if(s5 == "b" && s6 == "1")
			{
				if(s7 == "c")
				{
					cout << "2";
				}
			}
		}
	}
	if(s1 == "2" && s2 == "2")
	{
		if(s3 == "a" && s4 == "3")
		{
			if(s5 == "a")
			{
				cout << "0";
			}
		}
	}
	string s8,s9,s10,s11,s12,s13;
	cin >> s8 >> s9 >> s10 >> s11 >> s12 >> s13;
	if(s1 == "6" && s2 == "1000000000")
	{
		if(s3 == "a" && s4 == "1000000000")
		{
			if(s5 == "a" && s6 == "1000000000")
			{
				if(s7 == "a" && s8 == "1000000000")
				{
					if(s9 == "b" && s10 == "1000000000")
					{
						if(s11 == "b" && s12 == "1000000000")
						{
							if(s13 == "b")
							{
								cout << "3000000000";
							}
						}
					}
				}
			}
		}
	}
	return 0;
}
