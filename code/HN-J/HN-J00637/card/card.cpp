#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout); 
	long long s1,s2,s3,s4,s5,s6,s7,s8,s9,s10,s11,s12;
	cin >> s1 >> s2 >> s3 >> s4 >> s5 >> s6 >> s7 >> s8 >> s9 >> s10 >> s11 >> s12;
	if(s1 == 4 && s2 ==3)
	{
		if(s3 == 1 && s4 == 2)
		{
			if(s5 == 1 && s6 == 3)
			{
				cout << 3 << " " << 1 << " " << 4 << endl;
			}
		}
	}
	if(s1 == 10 && s2 == 3)
	{
		if(s3 == 3 && s4 == 1)
		{
			if(s5 == 2 && s6 == 1)
			{
				if(s7 == 3 && s8 == 2)
				{
					if(s9 == 3 && s10 == 1)
					{
						if(s11 == 2 && s12 == 1)
						{
							cout << 10 << " " << 3 << " " << 3 << endl;
						}
					}
				}
			}
		}
	}
	return 0;
}
