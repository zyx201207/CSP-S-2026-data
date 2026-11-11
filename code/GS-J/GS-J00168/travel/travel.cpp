#include <bits/stdc++.h>
using namespace std;

int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string c1,c2,s1,s2;
    cin >> c1 >> s1 >> c2 >> s2;
    int l1 = (int)(s1[0])*10 + (int)(s1[1]);
    int l2 = (int)(s2[0])*10 + (int)(s2[1]);
    char h1 = s1[2];
    char h2 = s2[2];
    if (c1 != c2)
    {
    	cout << "0000";
    	return 0;
	}
	else
	{
		if (l1 != l2)
		{
		    cout << "1000";
		    return 0;
		}
		else if (l1 == l2)
		{
		    if (h1=='A' && h2=='B'  ||  h1=='B' && h2=='A' ||
                h1=='B' && h2=='C'  ||  h1=='C' && h2=='B' ||
				h1=='D' && h2=='F'  ||  h1=='F' && h2=='D')
			{
			    cout << "1111";
			    return 0;
			}
			else if (h1=='A'&&h2=='C'  ||  h1=='C'&&h2=='A')
			{
				cout << "1110";
			    return 0;
			}
			else
			{
				cout << "1100";
				return 0;
			}
		}
	}
}

