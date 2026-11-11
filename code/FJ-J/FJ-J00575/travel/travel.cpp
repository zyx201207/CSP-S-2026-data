#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
long long r1=0,r2=0,x1=0,x2=0,l1,l2;
long long h1=c1.size()-1;
long long h2=c2.size()-1;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	for(int i=0;i<=h1;i++)
	{
		r1=r1*10+(c1[i]-'0');
	}
	for(int i=0;i<=h2;i++)
	{
		x1=x1*10+(c2[i]-'0');
	}
	for(int i=0;i<=1;i++)
	{
		r2=r2*10+(s1[i]-'0'); 
	}
	for(int i=0;i<=1;i++)
	{
		x2=x2*10+(s2[i]-'0'); 
	}
	l1=int(s1[2]);
	l2=int(s2[2]);
	if(r1==x1)
	{
		cout<<1;
	}
	else
	{
		cout<<0<<0<<0<<0;
		return 0;
	}
	if(r2==x2)
	{
		cout<<1;
	}
	else
	{
		cout<<0<<0<<0;
		return 0;
	}
	if(l1>=65&&l1<=67&&l2>=65&&l2<=67)
	{
		cout<<1;
		if(abs(l1-l2)==1)
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
		cout<<0<<0;
		return 0;
	}
	
	return 0; 
}
