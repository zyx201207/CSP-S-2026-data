#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n,c,l=0,sum=0;
	string a,s;
	cin>>n;
	for(long long i=1;i<=n;i++)
	{
		cin>>c>>a;
		l+=c;
		for(long long j=1;j<=c;j++)
		{
			s+=a;
		}
	}
	if(l%2!=0)
	{
		for(long long i=l/2+1;i<=l;i++)
		{
			if(s[i]!=s[l-i-1])
			{
				s[i]=s[l-i-1];
				sum++;
			}
		}
	}
	else
	{
		for(long long i=l/2;i<=l;i++)
		{
			if(s[i]!=s[l-i-1])
			{
				s[i]=s[l-i-1];
				sum++;
			}
		}
	}
	cout<<sum;
	return 0;
}
