#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int f=0;
	string c1,c2,s1,s2,p="",q="";
	char m,n;
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2)
	{
		cout<<1;
		f=1;
		for(int i=0;i<=s1.size()-1;i++)
		{
			if(s1[i]>='0'&&s1[i]<='9')
			{
				p+=s1[i];
			}
			else
			{
				m=s1[i];
			}
		}
		for(int i=0;i<=s2.size()-1;i++)
		{
			if(s2[i]>='0'&&s2[i]<='9')
			{
				q+=s2[i];
			}
			else
			{
				n=s2[i];
			}
		}
		if(p==q)
		{
			cout<<1;
			f=2;
			if((m=='A'&&n=='B')||(m=='A'&&n=='C')||(m=='B'&&n=='C')||(m=='B'&&n=='A')||(m=='C'&&n=='A')||(m=='C'&&n=='B')||(m=='D'&&n=='F')||(m=='F'&&n=='D'))
			{
				cout<<1;
				f=3;
				if((m=='A'&&n=='B')||(m=='B'&&n=='C')||(m=='B'&&n=='A')||(m=='C'&&n=='B')||(m=='D'&&n=='F')||(m=='F'&&n=='D'))
				{
					cout<<1;
					f=4;
				}
			}
		}
	}
	if(f==0)
	{
		cout<<0<<0<<0<<0;
	}
	else if(f==1)
	{
		cout<<0<<0<<0;
	}
	else if(f==2)
	{
		cout<<0<<0;
	}
	else if(f==3)
	{
		cout<<0;
	}
	return 0;
}
