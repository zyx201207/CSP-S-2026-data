#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	string a;
	long long n,l=0,s=0;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		int b;
		char c;
		cin>>b>>c;
		for(int j=l;j<=l+b-1;j++)
		{
			a[j]=c;
			s++;
		}
		l=l+b;
	}
	long long o=0,v=0;
	long long p=s-1;
	for(int i=1;i<=s/2;i++)
	{
		if(a[o]!=a[p]) v++;
		o++;
		p--;
	}
	cout<<v;
	return 0;
}