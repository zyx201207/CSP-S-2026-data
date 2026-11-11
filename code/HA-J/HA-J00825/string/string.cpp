#include<bits/stdc++.h>
using namespace std;
string s,s1,s2;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n,len=0;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		long long a;
		char b;
		cin>>a>>b;
		len+=a;
		for(int j=1;j<=a;j++)
		{
			s+=b;
		}
	}
	for(int i=0;i<len/2;i++)
	{
		s1+=s[i];
		s2+=s[len-i-1];
	}
	long long sum=0;
	for(int i=0;i<len/2;i++)
	{
		if(s1[i]!=s2[i])
		{
			sum++;
		}
	}
	cout<<sum;
	return 0;
}
