#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
string a{'0','0','0','0'};
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin.tie(0);
	cout.tie(0);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2)
	{
		a[0]='1';
		if(s1[0]==s2[0]&&s1[1]==s2[1])
		{
			a[1]='1';
			if(s1[2]=='A'||s1[2]=='B'||s1[2]=='C')
			{
				if(s2[2]=='A'||s2[2]=='B'||s2[2]=='C')
				{
					a[2]='1';
					if((s1[2]=='A'&&s2[2]=='C')||(s1[2]=='C'&&s2[2]=='A'))
						a[3]='0';
					else
						a[3]='1';
				}
			}
			else
			if(s2[2]=='D'||s2[2]=='F')
			{
				a[2]='1';
				a[3]='1';
			}
		}
	}	
	cout<<a;
	return 0;
}
