#include<bits/stdc++.h>//09:26
using namespace std;
int main()
{
	string s1,s2,c1,c2,a[5];
	a[0]='A',a[1]='B',a[2]='C',a[3]='D',a[4]='F';
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2)
	{
		cout<<1;
	}
	else
	{
		cout<<0000;
		return 0;
	}
	if(s1[0]==s2[0]&&s1[1]==s2[1])
	{
		cout<<1;
	}
	else
	{
		cout<<000;
		return 0;
	}//ccf什麽意思啊？300块的考试
	if(s1[2]=='A'&&s2[2]=='B'||s2[2]=='c')
	{
		cout<<1;
	}
	if(s1[2]=='B'&&s2[2]=='A'||s2[2]=='c')
	{
		cout<<1;
		
	}
		if(s1[2]=='c'&&s2[2]=='B'||s2[2]=='A')
	{
		cout<<1;
		
	}
		if(s1[2]=='D'&&s2[2]=='F')
	{
		cout<<1;
	}
		if(s1[2]=='F'&&s2[2]=='D')
	{
		cout<<1;
	}
	else
	{
		cout<<00;
		return 0;
	}
		for(int i=0;i<5;i++)
	{
		if(a[i]==s1[2])
		{
			if(a[i-1]==s2[2]||a[i+1]==s2[2])
			{
				cout<<1;
				break;
				return 0;
			}
		}
	}
	cout<<0;
	return 0;
}