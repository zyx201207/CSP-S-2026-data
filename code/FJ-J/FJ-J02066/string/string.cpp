#include<bits/stdc++.h>
using namespace std;
long long n,a,k=0;
string o="",p="";
char b;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(long long i=0;i<n;i++)
	{
		cin>>a>>b;
		for(long long j=0;j<a;j++)
		{
			o=o+b;
			p=b+p;
		}
	}
	for(long long i=0;i<o.size()/2;i++)
	{
		if(o[i]!=p[i])
		{
			o[i]=p[i];
			k++;
			p[o.size()-i-1]=p[i];	
		}
	}
	cout<<k;
	return 0;
}
