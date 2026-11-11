#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n,x,sum=0;
	char y;
	string b="";
	cin>>n;
	for(long long i=1;i<=n;i++)
	{
		cin>>x>>y;
		for(int j=0;j<x;j++)
		b+=y;
	}
	for(long long i=0;i<b.length()/2;i++)
	{
		if(b[i]!=b[b.length()-1-i])
		{
			sum++;
		}
	}
	cout<<sum;
	return 0;
}
