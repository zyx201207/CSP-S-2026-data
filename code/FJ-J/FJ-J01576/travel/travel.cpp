#include <bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
bool isside(string x,string y)
{
	char a = x[2],b = y[2];
	if (a == 'A' && (b == 'B' || b == 'C')) return true;
	if (a == 'B' && (b == 'A' || b == 'C')) return true;
	if (a == 'C' && (b == 'A' || b == 'B')) return true;
	if (a == 'D' && b == 'F') return true;
	if (a == 'F' && b == 'D') return true;
	return false;
}
bool isbes(string x,string y)
{
	char a = x[2],b = y[2];
	if ((int)a > (int)b) swap(a,b);
	if (a == 'C' && b == 'C') return false;
	if (a + 1 == b) return true;
	return false;
}
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin >> c1 >> s1 >> c2 >> s2;
	if (c1 == c2)
	{
		if ((s1[0] == s2[0]) && (s1[1] == s2[1]))
		{
			if (isside(s1,s2))
			{
				if (isbes(s1,s2)) cout << "1111";
				else cout << "1110";
			}
			else cout << "1100";
		}
		else cout << "1000";
	}
	else cout << "0000";
	return 0;
}
