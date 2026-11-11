#include<bits/stdc++.h>
using namespace std;
string c1,c2,s1,s2;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c1>>s1>>c2>>s2;
    if(c1!=c2)
    {
		cout<<"0000";
		return 0;
	}
	if(c1==c2)
	{
		int p1=(s1[0]-'0')*10+s1[1]-'0';
		int p2=(s2[0]-'0')*10+s2[1]-'0';
		if(p1!=p2)
		{
			cout<<"1000";
			return 0;
		}
		else
		{
			if((s1[2]<='C'&&s2[2]<='C')||(s1[2]>'C'&&s2[2]>'C'))
			{
				if((s1[2]>'C'&&s2[2]>'C')||(s1[2]<='C'&&s2[2]<='C'&&(s1[2]=='B'||s2[2]=='B')))
				{
					cout<<"1111";
				}
				else
				{
					cout<<"1110";
				}
			}
			else
			{
				cout<<"1100";
				return 0;
			}
		}
	}
    return 0;
}
