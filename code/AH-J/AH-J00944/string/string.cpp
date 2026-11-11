#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	long long a;
	char b;
	string s;
	for(int i=0;i<n;i++)
	{
		cin>>a>>b;
		for(long long j=0;j<a;j++)
		{
			s+=b;
		}
	}
	long long k=s.size(),m=0;
	for(long long i=0;i<k/2;i++)
	{
		if(a[i]!=a[k-i-1])
		{
			m++;
		}
	}
	cout<<m;
	return 0;
}
