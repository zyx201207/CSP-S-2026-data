#include<bits/stdc++.h>
using namespace std;
string a,b,c,d;
bool x1,x2,x3,x4;
bool x(char n,char m)
{
	return n=='B'||m=='B';
}
void f()
{
	if(a==c)
	{
		x1=1;
		if(b[0]==d[0]&&b[1]==d[1])
		{
			x2=1;
			if(b[2]>='A'&&b[2]<='C')
				if(d[2]>='A'&&d[2]<='C')
				{
					x3=1;
					x4=b[2]=='B'||d[2]=='B';
				}
				else
				{
					x3=0;
					x4=0;
				}
					
			else if(d[2]=='D'||d[2]=='F')
			{
				x3=1;
				x4=1;
			}
				
			else
			{
				x3=0;
				x4=0;
			}
				
		}
		else
		{
			x2=0;
			x3=0;
			x4=0;
		}
	}
	else
	{
		x1=0;
		x2=0;
		x3=0;
		x4=0;
	}
	return ;
}
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>b>>c>>d;
	f();
	cout<<x1<<x2<<x3<<x4;
	return 0;
}
