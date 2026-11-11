#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
	string a,b,c,d;
	cin>>a>>b>>c>>d;
	int sum1=0,sum2=0,sum3=0;
	if(b==d)
	{
		cout<<"0000";
		return 0;
	}
	if(a==c)
	{
		cout<<"1";
		sum1=1;
	}
	else
	{
		cout<<"0000";
		return 0;
	}
	
	string b1,d1;
	b1=b[0]+b[1];
	d1=d[0]+d[1];
	if(b1==d1 &&sum1==1)
	{
		cout<<"1";
		sum2=1;
		
	}
	else
	{
		cout<<"0";
	}
	
	char b3,d3;
	b3=b[2];
	d3=d[2];
	if(((b3<='C'&&d3<='C')||(b3>'C'&&d3>'C')) && sum2==1)
	{
		cout<<"1";
		sum3=1;
	}
	else
	{
		cout<<"0";
	}
	char b2,d2;
	b2=b[2];
	d2=d[2];
	if(sum3==1)
	{
		if((b2=='A' &&d2=='B') ||(b2=='B' &&d2=='A')||(b2=='B' &&d2=='C')||(b2=='C' &&d2=='B')||(b2=='D' &&d2=='F')||(b2=='F' &&d2=='D'))
		{
			cout<<"1";
		}
		else
	    {
		    cout<<"0";
		    return 0;
	    }
	}
	else
	{
		cout<<"0";
	}
	return 0;
 } 
