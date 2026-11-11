#include<bits/stdc++.h>
using namespace std;
int main()
{
	//freopen("travel.in","r",stdin);
	//freopen("travel.out","w",stdout);
	int c1,c2; 
	char s1,s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1=c2)
	{
		cout<<"1";
	}
	else
	{
		cout<<"0";
	}
	if(s1-s2<=4||s2-s1<=4)
	{
	cout<<"1"; 
	}
	else
	{
		cout<<"0";
	}
	if((s1+s2-21)%100==0||(s1+s2-22)%100==0||(s1+s2-23)%100==0||(s1+s2-24)%100==0||(s1+s2-25)%100==0&&(s1+s2-26)%100==0)
	{
		cout<<"1";
	}
	else
	{
		cout<<"0";
	}
	if(s1-s2<=1||s2-s1<=1)
	{
		cout<<"1";
	}
	else
	{
		cout<<"0";
	}
	return 0;
}
