#include <bits/stdc++.h>
using namespace std;
char s1[5],s2[5],r1,r2;
int l1,l2,c1,c2;
bool find(char r1,char r2)
{
	if (r1<='C'&&r2<='C')
		return true;
	if (r1>'C'&&r2>'C')
		return true;
	return false;
}
bool beside(char r1,char r2)
{
	if (abs(r1-r2)==1)
		return true;
	if (r1=='D'&&r2=='F'||r1=='F'&&r2=='D')
		return true;
	return false;
}
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1[1]>>s1[2]>>r1>>c2>>s2[1]>>s2[2]>>r2;
	l1=(s1[1]-'0')*10+s1[2]-'0';
	l2=(s2[1]-'0')*10+s2[2]-'0';
	if (c1!=c2)
		cout<<"0000";
	else
	{
		if (l1!=l2)
			cout<<"1000";
		else
		{
			if (!find(r1,r2))
				cout<<"1100";
			else
			{
				if (!beside(r1,r2))
					cout<<"1110";
				else
					cout<<"1111";
			}
		}
	}
	return 0;
}
