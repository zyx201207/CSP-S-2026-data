#include<bits/stdc++.h>
using namespace std;
long long k,n;
char l;
string s,p;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int sum=-1;
	cin>>n;
	while(n--)
	{
		cin>>k>>l;
		while(k--)
		{
			sum++;
			s[sum]=l;
		}
	}
	sum=-1;
	long long len=s.size();
	for(long long i=len-1;i>-1;i--)
	{
		sum++;
		p[sum]=s[i];
	}
	sum=0;
	if(s==p)
	{
		cout<<0;
		return 0;
	}
	cout<<len/2;
	return 0;
}
