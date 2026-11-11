#include<bits/stdc++.h>
using namespace std;
int c1,c2,p1,p2;
char s1[4],s2[4];
char l1,l2;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1[1]>>s1[2]>>s1[3]>>c2>>s2[1]>>s2[2]>>s2[3];
	p1 = s1[2] - '0';
	if(s1[1] == '1') p1 += 10;
	p2 = s2[2] - '0';
	if(s2[1] == '1') p2 += 10;
	l1 = s1[3];
	l2 = s2[3];
	if(c1 != c2)
	{
		cout<<"0000";
		return 0;
	}
	else if(c1 == c2)
	{
		cout<<"1";
		if(p1 != p2)
		{
			cout<<"000";
			return 0;
		}
		else if(p1 == p2)
		{
			cout<<"1";
			if((l1 == 'A'|| l1 == 'B'|| l1 == 'C') && (l2 == 'A'|| l2 == 'B'|| l2 == 'C') && l1 != l2)
			{
				cout<<"1";
				if((l1 == 'A' && l2 == 'B') || (l1 == 'B' && l2 == 'A') || (l1 == 'B' && l2 == 'C') || (l1 == 'C' && l2 == 'B') || (l1 == 'F' && l2 == 'D')|| (l1 == 'D' && l2 == 'F'))
				{
					cout<<"1";
					return 0;
				}
			}
			else if((l1 == 'F'|| l1 == 'D') && (l2 == 'F'|| l2 == 'D') && l1 != l2)
			{
				cout<<"1";
				if((l1 == 'A' && l2 == 'B') || (l1 == 'B' && l2 == 'A') || (l1 == 'B' && l2 == 'C') || (l1 == 'C' && l2 == 'B') || (l1 == 'F' && l2 == 'D')|| (l1 == 'D' && l2 == 'F'))
				{
					cout<<"1";
					return 0;
				}
			}
			else
			{
				cout<<"00";
				return 0;
			}
		}
	}
	return 0;
}