#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long  n,sum=0;
	string b[20010];
	int a[20010];
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>b[i];
		
	}
	for(int i= 1;i<=n;i++)
	{
		for(int j=n;j>=i;j++)
		{
			if(b[i]!=b[j])
			{
				cout<<a[i];
				return 0;
			}
			else
			{
				cout<<0;
				return 0;
			}
		}
	}
	return 0;
} 
