#include<bits/stdc++.h>
using namespace std;
char c11,c12,c21,c22,s11,s12,s13,s21,s22,s23;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c11>>c12;
	cin>>s11>>s12>>s13;
	cin>>c21>>c22;
	cin>>s21>>s22>>s23;
	if(c11==c21&&c12==c22)
	{
		cout<<1;
	}
	else
	{
		cout<<0;
		cout<<0;
		cout<<0;
		cout<<0;
		return 0;
	}
	if(s11==s21&&s12==s22)
	{
		cout<<1;
	}
	else
	{
		cout<<0;
		cout<<0;
		cout<<0;
		return 0;
	}
	if(s13=='A'||s13=='B'||s13=='C')
	{
		if(s23=='A'||s23=='B'||s23=='C')
		{
			cout<<1;
		}
		if(s23=='D'||s23=='F')
		{
			cout<<0;
			cout<<0;
			return 0;
		}
	}
	else if(s13=='D'||s13=='F')
	{
		if(s23=='D'||s23=='F')
		{
			cout<<1;
			cout<<1;
			return 0;
		}
		if(s23=='A'||s23=='B'||s23=='C')
		{
			cout<<0;
			cout<<0;
			return 0;
		}
	}
	if(s13=='A')
	{
		if(s23=='B')
		{
			cout<<1;
			return 0;
		}
		if(s23=='C'||s23=='D'||s23=='F')
		{
			cout<<0;
			return 0;
		}
	}
	else if(s13=='B')
	{
		if(s23=='A'||s23=='C')
		{
			cout<<1;
			return 0;
		}
		if(s23=='D'||s23=='F')
		{
			cout<<0;
			return 0;
		}
	}
	else if(s13=='C')
	{
		if(s23=='B')
		{
			cout<<1;
			return 0;
		}
		if(s23=='A'||s23=='D'||s23=='F')
		{
			cout<<0;
			return 0;
		}
	}
	else if(s13=='D'||s13=='F')
	{
		cout<<0;
		return 0;
	}
	return 0;
}
