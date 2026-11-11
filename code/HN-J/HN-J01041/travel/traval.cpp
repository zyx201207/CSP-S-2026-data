#include <bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin >> c1 >> s1 >> c2 >> s2;
	char a = s1[2],b = s2[2];
	if (int(a) > int(b)) swap(a,b);
	if (c1 == c2)
	{
		if (s1.substr(0,2) == s2.substr(0,2))
		{
			if ((a == 'A' && b == 'B') || (a == 'B' && b == 'C') || (a == 'D' && b == 'F') || (a == 'A' && b == 'C'))
			{
				if ((a == 'A' && b == 'B') || (a == 'B' && b == 'C') || (a == 'D' && b == 'F')) cout << "1111";
				else cout << "1110";
			}
			else cout << "1100";
		}
		else cout << "1000";
	}
	else cout << "0000";
	return 0;
}
