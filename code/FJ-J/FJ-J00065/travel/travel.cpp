#include <bits/stdc++.h>
using namespace std;
int a,b;
string s1,s2;
 
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin >> a >> s1 >> b >> s2;
	bool q = false,w = false,e = false,r = false;
	if(a == b)
	{
		q = true;
		if(s1[0] == s2[0])
		{
			if(s1[1] == s2[1])
			{
				w = true;
				if(s1[2] >= 'A' && s1[2] <= 'C')
				{
					if(s2[2] >= 'A' && s2[2] <= 'C')
					{
						e = true;
					}
				}
				if(s1[2] >= 'D' && s1[2] <= 'F')
				{
					if(s2[2] >= 'D' && s2[2] <= 'F')
					{
						e = true;
					}
				}
				if(e)
				{
					if(s1[2] - s2[2] == 1) r = true;
					if(s2[2] - s1[2] == 1) r = true;
				}
				
			}
		}
	}
		
	
	cout << q << w << e << r;
	return 0;
	
}
