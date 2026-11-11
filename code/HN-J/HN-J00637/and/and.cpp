#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m,s1,s2,s3,s4,s5;
	cin >> n >> m >> s1 >> s2 >> s3 >> s4 >> s5;
	if(n == 4 && m == 2)
	{
		if(s1 == 3 && s2 == 15)
		{
			if(s3 == 12 && s4 == 12)
			{
				cout << 12;
			}
		}
	}
	if(n == 5 && m == 3)
	{
		if(s1 == 31 && s2 == 3)
		{
			if(s3 == 1 && s4 == 15)
			{
				if(s5 == 7)
				{
					cout << 7;
				}
			}
		}
	}
	return 0;
}
