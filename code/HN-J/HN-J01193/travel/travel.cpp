#include<bits/stdc++.h>
using namespace std;
int c[100],x[100];
char s[100];
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	for(int i=1;i<=2;i++)
	{
		cin>>c[i]>>x[i]>>s[i];
	}

		if(c[1]==c[2])
		{
			cout<<1;
		}else
		{
			cout<<"0000";
			return 0;
		}
		if(x[1] == x[2])
		{
			cout<<1;
		}else
		{
			cout<<0;
		}
		if('A'<=s[1] && s[1]<='C' || s[1]=='D' && s[2]=='F' || s[1]=='F' && s[2]=='D')
		{
			cout<<1;
		}else
		{
			cout<<0;
		}
		if(s[1]>s[2])
		{
			if(s[1]==s[2]+'1')
			{
				cout<<1;
			}else
			{
				cout<<0;
			}
		}else if(s[1]<s[2])
		{
			if(s[1]==s[2]-'1')
			{
				cout<<1;
			}else
			{
				cout<<0;
			}
		}
	
	
	return 0;
}

