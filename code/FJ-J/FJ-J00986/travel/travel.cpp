#include<bits/stdc++.h>
using namespace std;
long long a,c;
string b,d;
char z[100]={'0','A','B','C'},y[100]={'0','D','F'};
int check(string s)
{
	int x=0;
	for(int i=0;i<=1;i++)
	{
		if(s[i]>='0'&&s[i]<='9')
		x=x*10+s[i]-'0';
	}
	return x;
}
int ch()
{
	int o=0,p=0;
	
	for(int i=1;i<=3;i++)
	{
		if(z[i]==b[2])o=1;
		if(z[i]==d[2])p=1;
	
	}
	for(int i=1;i<=2;i++)
	{
		if(y[i]==b[2])o=2;
		if(y[i]==d[2])p=2;
	}
	
	return (o==p? 1:0);
}
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>b>>c>>d;
	if(a==c)
	{
		cout<<"1";
		if(check(b)==check(d))
		{
			cout<<"1";
			if(ch())
			{
				cout<<"1";
				if(b[2]+1==d[2]||b[2]-1==d[2])cout<<"1";
				else cout<<"0";
			}
			else cout<<"00";
		}
		else cout<<"000";
	}
	else cout<<"0000";
	return 0;
}
