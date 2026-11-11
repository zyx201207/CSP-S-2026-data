#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n,a[100001],sum=0,x=0;
	char s[100001];
	string q="",w="",z="";
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>s[i];
	}
	for(int i=n;i>=1;i--)
	{
		for(int j=1;j<=a[i];j++)
		{
			q+=s[i];
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=a[i];j++)
		{
			w+=s[i];
			x++;
		}
	}
	for(int i=0;i<x;i++)
	{
		if(q[i]!=w[i])
		{
			q[i]=w[i];
			sum++;
			for(int j=x-1;j>=0;j--)
			{
				z+=q[j];
				
			}
			bool f=1;
			for(int k=0;k<=x;k++)
			{
				if(q[k]!=z[k])
				{
					f=0;
				}
			}
			if(f)
			{
				cout<<sum;
				fclose(stdin);
				fclose(stdout);
				return 0;
			}
			
			
		}
	}
	cout<<sum;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
