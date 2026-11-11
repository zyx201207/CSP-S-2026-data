#include<bits/stdc++.h>
using namespace std;
int s1,s2,c1,c2,side1,side2;
char tmp1,tmp2;
int side(char ch)
{
	if(ch<='C')
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin.tie(NULL);
	ios::sync_with_stdio(0);
	cin>>s1>>c1>>tmp1;
	side1=side(tmp1);
	cin>>s2>>c2>>tmp2;
	side2=side(tmp2);
	if(s1!=s2)
	{
		cout<<"0000";
		return 0;
	}
	else if(c1!=c2)
	{
		cout<<"1000";
		return 0;
	}
	else if(side1!=side2)
	{
		cout<<"1100";
		return 0;
	}
	else if(abs(tmp1-tmp2)!=1)
	{
		cout<<"1110";
		return 0;
	}
	else
	{
		cout<<"1111";
		return 0;
	}
}
