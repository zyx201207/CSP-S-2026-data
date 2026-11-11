#include<bits/stdc++.h>
using namespace std;
string s1,s2,s3,s4;
long long Ans1,Ans2,Ans3,Ans4;

string t1,t2;
char my_X1,my_X2;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>s1>>s2>>s3>>s4;
	if(s1!=s3)
	{
		cout<<0;
		cout<<0;
		cout<<0;
		cout<<0;
		return 0;
	}
	cout<<1;
	for(int i=0;i<=1;i++)
	{
		t1+=s2[i];
	}
	for(int i=0;i<=1;i++)
	{
		t2+=s4[i];
	}
	if(t1!=t2)
	{
		cout<<0;
		cout<<0;
		cout<<0;
		return 0;
	}
	cout<<1;
	if((s2[2]>='A'&&s2[2]<='C'&&s4[2]>='A'&&s4[2]<='C')||(s2[2]>='D'&&s2[2]<='F'&&s4[2]>='D'&&s4[2]<='F'))
	{
		cout<<1;
		my_X1=s2[2];
		my_X2=s4[2];
		if(my_X1>my_X2)
		{
			swap(my_X1,my_X2);
		}
		if(my_X1<='C')
		{
			if(my_X2-my_X1==1)
			{
				cout<<1;
			}
			else
			{
				cout<<0;
				return 0;
			}
		}
		else
		{
			if(my_X2-my_X1==2)
			{
				cout<<1;
			}
			else
			{
				cout<<0;
				return 0;
			}
		}
	}
	else
	{
		cout<<0;
		cout<<0;
		return 0;
	}
	return 0;
}
