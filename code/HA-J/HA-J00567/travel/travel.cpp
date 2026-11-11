#include<bits/stdc++.h>
using namespace std;
string s[5];
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	for(int i=1;i<=4;i++)
		cin>>s[i];
	if(s[1]==s[3])
	{
		cout<<1;
		if(s[2][0]==s[4][0]&&s[2][1]==s[4][1])
		{
			cout<<1;
			if(s[2][2]>='A'&&s[2][2]<='C'&&s[4][2]>='A'&&s[4][2]<='C')
			{
				cout<<1;
				if(s[2][2]+1==s[4][2]||s[2][2]-1==s[4][2])
					cout<<1;
				else
					cout<<0;
			}
			else if(s[2][2]>'C'&&s[2][2]<='E'&&s[4][2]>'C'&&s[4][2]<='E')
				cout<<1<<1;
			else
				cout<<0<<0;
		}
		else
			cout<<0<<0<<0;
	}
	else
		cout<<0<<0<<0<<0;
	return 0;
}
