#include <bits/stdc++.h>
using namespace std;
int c1,c2;
string s1,s2,s1p,s2p;
int p1,p2;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1 == c2) cout<<1;
	else
	{
		cout<<"0000";
		return 0;
	}
	s1p = s1[0];s1p += s1[1];
	s2p = s2[0];s2p += s2[1];
	char ch1 = s1[2],ch2 = s2[2];
	if(ch1 == 'A') p1 = 1;
	else
	{
		if(ch1 == 'B') p1 = 2;
		else
		{
			if(ch1 == 'C') p1 = 3;
			else
			{
				if(ch1 == 'D') p1 = 4;
				else           p1 = 5;
			}
		}
	}
	if(ch2 == 'A') p2 = 1;
	else
	{
		if(ch2 == 'B') p2 = 2;
		else
		{
			if(ch2 == 'C') p2 = 3;
			else
			{
				if(ch2 == 'D') p2 = 4;
				else           p2 = 5;
			}
		}
	}
	if(s1p == s2p) cout<<1;
	else
	{
		cout<<"000";
		return 0;
	}
	if(p1 == 4 || p1 == 5)
	{
		if(p2 == 4 || p2 == 5) cout<<1;
		else
		{
			cout<<"00";
			return 0;
		}
	}
	else
	{
		if(p2 != 4 && p2 != 5) cout<<1;
		else
		{
			cout<<"00";
			return 0;
		}
	}
	if(abs(p1 - p2) == 1)
	{
		cout<<1;
	}
	else cout<<0;
	return 0;
}
/*
02 01A 02 01B
*/
