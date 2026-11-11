#include<bits/stdc++.h>
using namespace std;
long long a,s,d,f,g,a1,s1,d1,x;
char qw,qw1; 
int main ()
{
freopen("travel.in","r",stdin);
freopen("travel.out","w",stdout);
cin>> a >> s >> qw >> a1 >> s1 >> qw1;
if(a==a1)
{
	cout<<1;
}
else
{
	
	cout<<0<<0<<0<<0;
	return 0;
}
if(s==s1)
{
	cout<<1;
}
else
{
	cout<<0;
}
if(s==s1)
{
	if(qw=='A' or qw=='B' or qw=='C') 
	{
		if(qw1=='A' or qw1=='B' or qw1=='C')
		{
			cout<<1;
			x=1;
		}
	}
	else
	{
		if(qw=='D' or qw=='F')
		{
			if(qw1=='D' or qw1=='F')
			{
				cout<<1;
				x=1;
			}
		}
	}
}
if(x==0)
{
	cout<<0;
}
if(s==s1)
{
	if((qw==qw1+1 or qw==qw1-1)and !((qw=='C' and qw1=='D') or (qw=='C' and qw1=='D')))
	{
		cout<<1;
	}
	else
	{
		cout<<0;
	}
}
else
{
	cout<<0;
}
fclose(stdin);
fclose(stdout);
return 0;
}

