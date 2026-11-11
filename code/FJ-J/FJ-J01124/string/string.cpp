#include<bits/stdc++.h>
#include<string>
using namespace std;

int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
long long n,d=0,s=0;
string str;
	cin>>n;
	long long a[n],m[n];
	string b;
	for(long long i=0;i<n;i++)
	{
		cin>>a[i];
		s=s+a[i];
		m[i]=s;
		cin>>b[i];
	}
	for(long long i=0;i<n;i++)
	{
		if(i==0)
		{
			for(long long j=0;j<m[i];j++)
			{
				str[j]=b[i];
			}
		}
		else
		{
			for(long long j=m[i-1];j<m[i];j++)
			{
				str[j]=b[i];
			}
		}
	}
	for(long long i=0;i<s/2;i++)
	{
		if(str[s-i-1]!=str[i])
		{
			str[s-i-1]=str[i];
			d++;
		}
	}
	cout<<d;
	return 0;
}
