#include<bits/stdc++.h>
using namespace std;

int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	int c1_=c1[1]-'0';
	int c2_=c2[2]-'0';
	if(c1==c2)
	{
		cout<<'1';
	}
	else
	{
		cout<<'0';
		cout<<'0'<<'0'<<'0';
		return 0;
	}
	int p1=s1[1]-'0';
	int p2=s2[1]-'0';
	if(p1==p2)
	{
		cout<<'1';
	}
	else
	{
		cout<<'0';
		cout<<'0'<<'0';
		return 0;
	}
	int ce1=s1[2]-'A'+1;
	int ce2=s2[2]-'A'+1;
	if(ce1>=1 && ce1<=3 && ce2>=1 && ce2<=3)
	{
		cout<<'1';
		int x=ce1-ce2;
		if(x==1 || x==-1)
		{
			cout<<'1';
		}
		else
		{
			cout<<'0';
		}
	}
	else if(ce1>=4 && ce1<=5 && ce2>=4 && ce2<=5)
	{
		cout<<'1';
		int x=ce1-ce2;
		if(x==1 || x==-1)
		{
			cout<<'1';
		}
		else
		{
			cout<<'0';
		}
	}
	else
	{
		cout<<'0';
		cout<<'0';
	}
	return 0;
}
