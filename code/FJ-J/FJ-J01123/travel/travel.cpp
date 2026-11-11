#include <bits/stdc++.h>

using namespace std;
int getSize(char ch)
{
	if(ch == 'A' || ch == 'B' || ch == 'C')
		return 1;
	else if(ch == 'D' || ch == 'F')	return 2;
}
bool GEt(char x,char y)
{
	
	if(x != y)
	{
		if(getSize(x) == 1 && getSize(y) == 1)
		{
			if(x == 'A')
			{
				if(y == 'C')	return false;
				else	return true;
			}
			else if(x == 'B')	return true;
			else if(x == 'C')
			{
				if(y == 'A')	return false;
				else	return true;
			}
		}
		else return true;
	}
		
	else	return false;
	
}
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string s1,s2,s3,s4;
	cin >> s1 >> s2 >> s3 >> s4;
//	cout <<" "<< s1 << " " << s2 << " " << s3 << " " << s4 << " ";
	if(s1[0] == s3[0])
	{
		if(s1[1] == s3[1])
		{
			cout << 1;
		}
		else
		{
			cout << 0 << 0 <<0 <<0;
			return 0;
		}
	}
	else
	{
		cout << 0 << 0 <<0 <<0;
		return 0;
	}
	
	if(s2[0] == s4[0])
	{
		if(s2[1] == s4[1])
		{
			cout << 1;
			if(getSize(s2[2]) == getSize(s4[2]))
			{
				cout << 1;
				if(GEt(s2[2],s4[2]))
					cout << 1;
				else
					cout << 0;
			}
			else
			{
				cout << 0 << 0;
				return 0;
			}
		}
		else	
		{
			cout << 0 << 0 <<0;
			return 0;
		}
	}
	else
	{
		cout << 0 << 0 << 0;
		return 0;
	}
	return 0;
}