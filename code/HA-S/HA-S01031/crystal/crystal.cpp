#include<bits/stdc++.h>
using namespace std;
long long a,sum=0,max1=0,biao=1;
long long b;
long long m[1000000],n[1000000];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
//	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0); 
	
	cin>>a>>b;
	if(a==1)
	cout<<1;
	if(a>=2)
	{
		cin>>m[0]>>m[1];
	for(long long i=2;i<a;i++)
	{
		cin>>m[i];
		if(m[i]-m[i-1]!=m[i-1]-m[i-2] )
		biao=0;	
	}
	if(biao==1)
	{	
		int x=m[1]-m[0];
		int y=x;
		while(sum+x<b)
		{
		sum=sum+x;
		x=x+y;	
		}
		cout<<x/y+1;
	}
	else
	{
		sort(m,m+a);
	for(long long i=1;i<a;i++)
	{
	n[i]=m[i]-m[i-1];
	}
	for(long long i=1;i<a;i++)
	{
		if(max1>=a-i)
		break;
		for(long long l=i;l<a;l++)
		{
			
			sum=sum+n[l]*(l-i+1);
			if(sum>b)
			{
				max1=max(max1,l-i+1);
				break;
			}
			if(l==a-1)
			max1=max(max1,a-i);
		}
	sum=0;
	}
	cout<<max1;	
	}	
	}


	return 0;
}
