#include<bits/stdc++.h>

using namespace std;

string c1, s1, c2, s2, l1, l2;
char st1, st2;

int main()
{
 	freopen("travel.in", "r", stdin);
 	freopen("travel.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	
	cin >> c1 >> s1 >> c2 >> s2;
	cout << (c1 == c2);
	if(c1 != c2)
	{
		cout << "000";
		return 0;
	}
	l1 = s1[0] + s1[1], l2 = s2[0] + s2[1];
	cout << (l1 == l2);
	if(l1 != l2)
	{
		cout << "00";
		return 0;
	}
	st1 = s1[2], st2 = s2[2];
	bool lin = (st1 <= 'C' && st2 <= 'C') || (st1 >= 'D' && st2 >= 'D');
	cout << lin;
	if(lin != true)
	{
		cout << "0";
		return 0;
	}
	cout << ((st1 >= 'D' && st2 >= 'D') || (st1 <= 'C' && st2 <= 'C' && abs(st1 - st2) == 1));
	
	return 0;
}
