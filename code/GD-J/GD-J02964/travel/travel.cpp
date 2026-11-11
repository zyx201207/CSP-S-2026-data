#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int check1(string a,string b)
{
	if(int(a[2])<68 && int(b[2])<68)
	{
		return 1;
	}
	else if(int(a[2])>67 && int(b[2])>67)
	{
		return 1;
	}
	return 0;
}
int check2(string a,string b)
{
	if(int(a[2])-int(b[2]) == 1)
	{
		return 1;
	}
	if(int(b[2])-int(a[2]) == 1)
	{
		return 1;
	}
	return 0;
}
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin >> c1 >> s1 >> c2 >> s2;
	if(c1 == c2)
	{
		cout << 1;
		if(s1[0]==s2[0] && s1[1]==s2[1])
		{
			cout << 1;
			if(check1(s1,s2))
			{
				cout << 1;
				if(check2(s1,s2))
				{
					cout << 1;
				}
				else
				{
					cout << 0;
				}
			}
			else
			{
				cout << "00";
			}
		}
		else
		{
			cout << "000";
		}
	}
	else
	{
		cout << "0000";
	}
	return 0;
}
