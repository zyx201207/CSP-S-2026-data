#include<bits/stdc++.h>
using namespace std;
long long x[200005];
char y[200005];
long long cnt[200005];
string a;
string b;
bool c;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n,num=0,sum=0;
	cin>>n;
	for(int i=1;i<=n;i++)
	{		
		cin>>x[i]>>y[i];
		sum+=x[i];
		for(int j=1;j<=x[i];j++)
		{
			a+=y[i];
		}				
	}
	for(int i=a.length();i>=1;i--)
	{
		b+=a[i];
	}
	for(int i=1;i<=n;i++)
	{
		if(a[i]!=b[i])
		{
			c=1;
		}
	}
	if(c)
	{
		if(n%2==1)
		{
			if(a[a.length()/2+1]==b[a.length()/2+1])
			cout<<a.length()/2;
			else
			{
				for(int i=1;i<=n;i++)
				{
					cnt[(int)y[i]]+=x[i];
				}
				for(int i=1;i<=n;i++)
				{
					num=max(num,cnt[i]);
					
				}
				cout<<sum-num;
			}
		}
		else
		{
			if(a[a.length()/2]==b[a.length()/2]&&a[a.length()/2+1]==b[a.length()/2+1])
			{
				cout<<a.length()/2-1;
			}
			else
			{
				for(int i=1;i<=n;i++)
				{
					cnt[(int)y[i]]+=x[i];
				}
				for(int i=n;i>=1;i--)
				{
					cnt[(int)y[i]]+=x[i];
				}
				for(int i=1;i<=n;i++)
				{
					num=max(num,cnt[i]);
					
				}
				cout<<sum-num;
			}
		}
	}
	else
	{
		cout<<0;
		return 0;
	}
	return 0;
}
