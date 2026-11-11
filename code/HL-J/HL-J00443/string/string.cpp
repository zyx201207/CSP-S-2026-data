#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n,c;
	long long sum=0;
	string d,a;
	cin>>n;
	while(n--)
	{
		cin>>c>>d;
		for(long long i=0;i<c;i++)
		{
			a+=d;
		}
	}
	long long s=a.length();
	long long m=0;
	if(s%2==0)
	{
		m=s/2;
	}
	else
	{
		m=s/2+1;
	}
	for(long long i=0;i<m;i++)
	{
		if(a[i]!=a[s-1-i])
		{
			sum++;
		}
	}
	cout<<sum;
	return 0;
}
