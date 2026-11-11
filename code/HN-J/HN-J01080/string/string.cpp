#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out ","w",stdout); 
	long long n,x;
	string a,b,c;
	int z=0;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>x;
		cin>>a;
		for(int j=0;j<x;j++)
		{
			b=b+a;
		}
	}
	long long cnt=0;
	int m=b.size()/2;
	for(int i=0;i<m;i++)
	{
		c=b[i]+c;
	}
	for(int i=0;i<m;i++)
	{
		if(b[m+i]==c[i]&&z==0)z=0;
		else 
		{
			z=1;
			cnt++;
		}
	}
	if(z==0)
	{
		cout<<0;
	}
	else cout<<cnt;
    return 0;
}

