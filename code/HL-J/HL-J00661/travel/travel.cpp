#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string s,s1,c,c1;
	cin>>s>>s1>>c>>c1;
	bool f=0,f1=0,f2=0,f3=0;
	if(s==c)
	{
		f=1;
	}
	else
	{
		cout<<f<<f1<<f2<<f3;
		return 0;
	}
	int a=0;
	for(int i=0;i<3;i++)
	{
		if(i<2)
		{
			if(s1[i]==c1[i])
			{
				a++;
			}
		}
		if(a==2)
		{
			f1=1;
		}
		if(s1[2]>='A'&&s1[2]<='C'&&c1[2]>='A'&&c1[2]<='C'&&f1==1||s1[2]>='D'&&s1[2]<='F'&&c1[2]>='D'&&c1[2]<='F'&&f1==1)
		{
			f2=1;
		}
		if(s1[2]==c1[2]+1&&f1==1||s1[2]+1==c1[2]&&f1==1)
		{
			if(s1[2]=='C'&&c1[2]=='D'||s1[2]=='D'&&c1[2]=='C')
			{
				f3=0;
			}
			else
			{
				f3=1;
			}
		}
	}
	cout<<f<<f1<<f2<<f3;
	return 0;
} 
