#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","W",stdout);
	int n,sum=0,m=0,ans;
	string s,s1;
	cin>>n;
	if(n==1)
	{
		cout<<0;
		return 0;
	}
	for(int i=1;i<=n;i++)
	{
		string x;
		int a;
		cin>>a>>x;
		m+=a;
		for(int j=1;j<=a;j++)
		{
			s+=x;
		}
	}
	for(int i=m-1;i>=0;i--)
	{
		s1+=s[i];
	}
	if(m%2!=0)
	{
		ans=m/2;
		for(int i=0;i<=ans;i++)
		{
			if(s[i]!=s1[i])
			{
				sum++;
			}
		}
	}
	else if(m%2==0)
	{
		ans=m/2-1;
		for(int i=0;i<=ans;i++)
		{
			if(s[i]!=s1[i])
			{
				sum++;
			}
		}
	}
	cout<<sum;
	return 0;
} 
