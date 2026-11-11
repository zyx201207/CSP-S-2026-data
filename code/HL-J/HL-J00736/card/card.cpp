#include<bits/stdc++.h>
using namespace std;
int a,b,d,f,s[15],w,l,o;   
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>a>>b;
		int c[a],z[b+5];
	for(int i=1;i<=a;i++)
	{
		cin>>c[i];
		if(i==a)
		{
			 l=c[i];
		}
	}
	for(int i=1;i<=b+3;i++)
	{
		z[i]=0;
	}
	for(int i=1;i<=a;i++)
	{
	f=c[i];
	w++;
	s[f]=1;
	if(s[f]==1)
	{
		for(int k=1;k<=w;i++)
		{
			s[f]=0;
		}
		d=0;
	} 
	d=d*10+f;
		while(d>0)
		{
			o=d%10;
			z[o]++;  	         
			d/=10;
	 }
	}
	for(int i=1;i<=a;i++)       
{
if(l==i)		
		{
		cout<<a<<" ";
	}
	else	
		{
		cout<<z[i]<<" ";
	}
}
	return 0;
}                           