#include<bits/stdc++.h>
using namespace std;
long long a,b,c[90000000],d,e=0,f;
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
	cin>>a>>b;	
	for(long long i=1;i<=a;i++)
	{
		cin>>c[i];
	}
	sort(c+1,c+1+a);
	d=upper_bound(c+1,c+1+a,b)-(c+1);
	
	for(long long i=1;i<=d;i++)
	{
	    e+=c[i];	
	}
	f=upper_bound(c+1,c+1+a,(e+b)/d)-(c+1);
	cout<<f;
} 
