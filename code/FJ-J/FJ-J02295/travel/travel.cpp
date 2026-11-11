#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a1,b1,a2,b2;
	cin >> a1 >> b1 >> a2 >> b2;
	bool f1,f2,f3,f4;
	if(a1 == a2)
	{
		f1 = true;
	}
	else
	{
		cout << "0000";
		return 0;
	}
	string c1,c2;
	c1 = b1[0] + b1[1];
	c2 = b2[0] + b2[1];
	if(c1 == c2)
	{
		f2 = true;
	}
	else
	{
		cout << "1000";
		return 0;
	}
	c1 = b1[2];
	c2 = b2[2];
	if((c1 <= "C") && (c2 <= "C"))
	{
		f3 == true;
	}
	else if(((c1 > "C") && (c1 <= "F")) && ((c2 > "C") && (c2 <= "F")))
	{
		f3 == true;
	}
	else
	{
		cout << "1100";
		return 0;
	}
	char c = b1[2];
	char d = b2[2];
	if((c-d==1) || (d-c==1))
	{
		cout << "1111";
	}
	else
	{
		cout << "1110";
	}
	return 0;
}
