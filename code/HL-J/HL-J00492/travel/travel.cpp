#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int a,b,i,g;
	bool f=false,j=false,h=false,l=false;;
	string c,d,e;
	cin>>a>>c>>b>>d;
	if(a==b)
	{
		cout<<"1";
		f=true;
	}
	else
	{
		cout<<"0";
		f=false;
	}
	if(c[0]==d[0])
	{
		if(c[1]==d[1])
		{
			j=true;
		}
		else
		{
			j=false;
		}
	}
	
	if(f&&j)
	{
		cout<<"1";
	}
	else
	{
		cout<<"0";
	}
	i=c[2];
	g=d[2];
	if(i==67&&g==68 || i==68&&g==67)
	{
		h=false;
	}
	else
	{
		h=true;
		if(i+1==g||i-1==g)
		{
			l=true;
		}
		else{
			l=false;
		}
	}
	if(f&&j&&h)
	{
		cout<<"1";
	}
	else
	{
		cout<<"0";
	}
	if(f&&j&&h&&l)
	{
		cout<<"1";
	}
	else
	{
		cout<<"0";
	}
	return 0;
}
