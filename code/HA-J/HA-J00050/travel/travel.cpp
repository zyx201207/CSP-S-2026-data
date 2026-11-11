#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin >> c1 >>s1 >>c2 >>s2;
	bool f1=false;
	if (c1 == c2)
	{
		cout << '1';
		f1 = true;
	}
	else
		cout << '0';
	bool f2=false;
	if (f1 && (s1[0] == s2[0] && s1[1] == s2[1]))
	{
		cout << '1';
		f2 = true;
	}
	else
		cout << '0';
	bool f3=false;
	if (f1 && f2 && (((s1[2] <= 67 && s2[2] <= 67) && abs(s1[2]-s2[2]) <= 2) || ((s1[2] >= 68 && s2[2] >= 68) && abs(s1[2]-s2[2]) == 1)))
	{
		cout << '1';
		f3 = true;
	}
	else
		cout << '0';
	if (f1 && f2 && f3 && abs(s1[2]-s2[2]) == 1)
		cout << '1';
	else
		cout <<'0';
	cout << '\n';
	return 0;
}
