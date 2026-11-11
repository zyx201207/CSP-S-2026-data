#include<bits/stdc++.h>
using namespace std;
string a,b,c,d;
int n,m;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","W",stdout);
	cin>>a>>b>>c>>d;
	for(int i=0;i<2;i++)
	{
		n=n*10+a[i]-'0';
		m=m*10+c[i]-'0';
	}
	if(n==m)//1
	{
		cout<<1;
		n=0,m=0;
		for(int i=0;i<2;i++)
		{
			n=n*10+b[i]-'0';
			m=m*10+d[i]-'0';
		}
		if(n==m)//2
		{
			cout<<1;
			if(b[2]<'D'&&d[2]<'D')//3
			{
				int p=0;
				cout<<1;
				if(b[2]=='D'&&d[2]=='C') p=1;
				if(d[2]=='D'&&b[2]=='C') p=1;
				if(abs(b[2]-d[2])==1&&p!=1)//4
				{
					cout<<1;
				}
				else 
				{
					cout<<0;
					return 0;
				}
			}
			else if(b[2]>'C'&&d[2]>'C')
			{
				int f=0;
				cout<<1;
				if(b[2]=='D'&&d[2]=='C') f=1;
				if(d[2]=='D'&&b[2]=='C') f=1;
				if(abs(b[2]-d[2])==1&&f!=1)//4
				{
					cout<<1;
				}
				else 
				{
					cout<<"0";
					return 0;
				}
			}
			else 
			{
				cout<<"00";
				return 0;
			}	
		}
		else 
		{
			cout<<"000";
			return 0;
		}
	}
	else 
	{
		cout<<"0000";
		return 0;
	}
	
	return 0;
}
