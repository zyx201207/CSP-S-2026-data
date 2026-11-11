#include<bits/stdc++.h>
using namespace std;
long long a[20001];
char c[20001];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n,sum=0;
	cin>>n;
	string s1,s2;
	bool b=1;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>c[i];
	}
	for(int i=1;i<n;i++)
	{
		if(a[i]!=a[i+1])
		{
			b=0;
			break;
		}
	}
	if(b==1)
	{
		sum=n;
		for(int i=1;i<=n;i++)
		{
			
			s1+=c[i];
		}
		for(int i=n;i>=1;i--)
		{
			s2+=c[i];
		}
	}
	else
	{
		for(int i=n;i>=1;i--)
		{
			sum+=a[i];
			for(int j=1;j<=a[i];j++)
			{
				s2+=c[i];
			}
		}
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=a[i];j++)
			{
				s1+=c[i];
			}
		}
	}
	if(s1==s2)
	{
		cout<<0;
		return 0;
	}
	else
	{
		int sum2=0;
		for(int i=0;i<sum;i++)
		{
			if(s1[i]!=s2[i])
			{
				sum2++;
			}
		}
		if(b==1)
		{
			cout<<sum2*a[1]/2;
		}
		else cout<<sum2/2;
		return 0;
	}
}
