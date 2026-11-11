#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel1.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	string a="A",b="B",c="C",d="D",f="F";
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2)
	{
		cout<<"1";
		if(s1[0]==s2[0]&&s1[1]==s2[1])
		{
			cout<<"1";
			if(s1[2]==a[0]||s1[2]==b[0]||s1[2]==c[0])
			{
				if(s2[2]==a[0]||s2[2]==b[0]||s2[2]==c[0])
				{
					cout<<"1";
					if(s1[2]==a[0]&&s2[2]==b[0])
					{
						cout<<"1";
					}
					else if(s1[2]==b[0])
					{
						if(s2[2]==a[0]||s2[2]==c[0])
						{
							cout<<"1";
						}
					}
					else if(s1[2]==c[0]&&s2[2]==b[0])
					{
						cout<<"1";
					}
					else if(s1[2]==d[0]&&s2[2]==f[0])
					{
						cout<<"1";
					}
					else if(s1[2]==f[0]&&s2[2]==d[0])
					{
						cout<<"1";
					}
					else
					{
						cout<<"0";
					}
				}
				else
				{
					cout<<"00";
				}
			}
			else if(s1[2]==d[0]||s1[2]==f[0])
			{
				if(s2[2]==d[0]||s2[2]==f[0])
				{
					cout<<"1";
					if(s1[2]==a[0]&&s2[2]==b[0])
					{
						cout<<"1";
					}
					else if(s1[2]==b[0])
					{
						if(s2[2]==a[0]||s2[2]==c[0])
						{
							cout<<"1";
						}
					}
					else if(s1[2]==c[0]&&s2[2]==b[0])
					{
						cout<<"1";
					}
					else if(s1[2]==d[0]&&s2[2]==f[0])
					{
						cout<<"1";
					}
					else if(s1[2]==f[0]&&s2[2]==d[0])
					{
						cout<<"1";
					}
					else
					{
						cout<<"0";
					}
				}
				else
				{
					cout<<"00";
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
 } 
