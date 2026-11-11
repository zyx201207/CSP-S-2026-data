#include<bits/stdc++.h>
using namespace std;
int main()
{
	//freopen("string.in","r",stdin);	
	//freopen("string.out","w",stdout);	
	long long a,c=0;
	string b;
	cin>>a;
	for(long long i=1;i<=a;i++)
	{
		long long m;
		char d;
		cin>>m>>d;
		for(long long j=1;j<=m;j++)
		{
			b+=d;
		}
	} 
	for(long long i=0;i<b.size();i++)
	{
		if(b[i]!=b[(b.size())-i-1])
		{
			
			b[i]=b[(b.size())-i-1];
			c++;
		}
	}
	cout<<c;
 } 
