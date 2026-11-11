#include <bits/stdc++.h>
using namespace std;
int main()
{
	//freopen("travel.in","r",stdin);
	//freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	int n1=0,n2=0,n3=0,n4=0;
	cin >> c1 >> s1 >> c2 >> s2;
	if (c1 == c2)
	{
		n1 = 1;
		if (s1[0] == s2[0] && s1[1] == s2[1])
		{
			n2 = 1;
			if ((s1[2] <= 'C' && s2[2] <= 'C') || (s1[2] >= 'D' && s2[2] >= 'D'))
			{
				n3 = 1;
				if (s1[2] + 1 == s2[2] || s1[2] - 1 == s2[2])
				{
					n4 = 1;
				}
			}
		}
	}
	cout << n1 << n2 << n3 << n4;
	return 0;
} 
