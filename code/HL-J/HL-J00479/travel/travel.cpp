#include <bits/stdc++.h>
#include <string>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin >>c1 >>s1 >>c2 >>s2;
	string t1 = s1.substr(0,2);
	string t2 = s2.substr(0,2);
	char p1 = s1[2];
	char p2 = s2[2];
	if (c1==c2)
	{
		cout << '1';
	}
	else 
	{
		cout << "0000";
		return 0;
	}
	if (t1 == t2)
	{
		cout << '1';
	}
	else 
	{
		cout << "000";
		return 0;
	}
	if ((p1 == 'A' && p2 == 'B') || (p1 == 'B' && p2 == 'A') || (p1 == 'A' && p2 == 'C') || (p1 == 'C' && p2 == 'A') || (p1 == 'B' && p2 == 'C') || (p1 == 'C' && p2 == 'B') || (p1 == 'D' && p2 == 'F') || (p1 == 'F' && p2 == 'D'))
	{
		cout << '1';
	}
	else cout << '0';
	if ((p1 == 'A' && p2 == 'B') || (p1 == 'B' && p2 == 'A') || (p1 == 'B' && p2 == 'C') || (p1 == 'C' && p2 == 'B') || (p1 == 'D' && p2 == 'F') || (p1 == 'F' && p2 == 'D'))
	{
		cout << '1';
	}
	else cout << '0';
	return 0;
}
