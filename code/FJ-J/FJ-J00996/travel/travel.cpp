#include<bits/stdc++.h>
using namespace std;
bool flag1,flag2,flag3,flag4;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a,b,c,d;
	cin>>a>>b>>c>>d;
	int x,y;
	x=a[0]*10+a[1];
	y=c[0]*10+c[1];
	if(x==y) 
	{
		flag1=1;
		if(b[0]*10+b[1]==d[0]*10+d[1])
		{
			flag2=1;
			if((b[2]=='A'&&(d[2]=='B'||d[2]=='C'))||(b[2]=='B'&&(d[2]=='A'||d[2]=='C'))||(b[2]=='C'&&(d[2]=='A'||d[2]=='B'))||(b[2]=='D'&&d[2]=='E')||(b[2]=='E'&&d[2]=='D'))
			{
				flag3=1;
				if((b[2]=='A'&&d[2]=='B')||(b[2]=='B'&&(d[2]=='A'||d[2]=='C'))||(b[2]=='C'&&d[2]=='B')||(b[2]=='E'&&d[2]=='D')||(b[2]=='D'&&d[2]=='E'))
				{
					flag4=1;
				}
			}
		}	 	
		cout<<flag1<<flag2<<flag3<<flag4;
	} 
	else
	{
		cout<<"0000";
	}
	return 0;
 }

