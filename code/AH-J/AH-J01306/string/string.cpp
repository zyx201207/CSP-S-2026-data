#include<bits/stdc++.h>
using namespace std;
long long a[10000000];
long long x=0,mid,s=0;
long long n;
string b,c;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		cin>>b[i];
		for(int j=0;j<a[i];j++)
		{
			c[x++]=b[i];
		}
	}
	mid=x/2;
	x-=1;
	for(int i=0;i<=mid;i++,--x)
	{
		if(c[i]!=c[x]) 
			s++;
	}
	cout<<s;
	return 0;	
} 
