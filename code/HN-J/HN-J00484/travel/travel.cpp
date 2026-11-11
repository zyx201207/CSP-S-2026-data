#include<bits/stdc++.h>
using namespace std;
char s1,s2;
int a1,a2,a3,a4;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a1>>a2>>s1>>a3>>a4>>s2;
	if(a1==a3)
	{
		cout<<1;
		if(a2==a4)
		{
			cout<<1;
			if((s1<='C'&&s2<='C')||(s1>'C'&&s2>'C'))
			{
				cout<<1;
				if(abs(s1-s2)==1)
				{
					cout<<1;
				}
				else
				{
					cout<<0;
				}
			}
			else
			{
				cout<<"00";
			}
		}
		else
		{
			cout<<"000";
		}
	}
	else
	{
		cout<<"0000";
	}
	return 0;
}
