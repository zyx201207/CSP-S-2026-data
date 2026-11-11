#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n;cin>>n;
	string d=0;string e=0;
	long long c=0;
	long long number=0;
	for(long long i=0;i<n;i++)
	{
		long long a;char b;
		cin>>a>>b;
		for(long long j=c;j<c+a;j++)
			d[j]=b;
		c+=a;
	}
	long long j=c;
	for(long long i=0;i<c;i++)
	{
		e[i]=d[j];
		j--;
	}
	for(long long i=0;i<c;i++)
	{
		if(e[i]!=d[i])
			number++;
	}
	cout<<number;
	return 0;
}
