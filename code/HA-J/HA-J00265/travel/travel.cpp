#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int c1,c2,s1,s2;
	char y1,y2;
	cin>>c1>>s1>>y1>>c2>>s2>>y2;
	if(c1==c2)
	{
		cout<<1;
		if(s1==s2)
		{
			cout<<1;
			if((y1<'D'&&y2<'D')||(y1>'C'&&y2>'C'))
			{
				cout<<1;
				if(y1==y2+1||y1==y2-1)
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
				cout<<0;
				cout<<0;
			}
		}
		else
		{
			cout<<0;
			cout<<0;
			cout<<0;
		}
	}
	else
	{
		cout<<0;
		cout<<0;
		cout<<0;
		cout<<0;
	}
	return 0;
} 
