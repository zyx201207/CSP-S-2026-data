#include<bits/stdc++.h>
using namespace std;
long long a[100005],s[100005]={0};
int main()
{
	//freopen("card.in","r",stdin);
	//freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<n;i++)
	{
		long long sum[100005]={1};
		for(int j=i;j<=n;j++)
		{
			if(a[j]==a[i])
			{
				for(int h=i;h<j;h++)
				{
					sum[h]=0;
				}
			}
		}
		for(int p=1;p<=n;p++)
		{
			s[a[i]]+=sum[i];
		}
	}
	for(int i=1;i<=m;i++)
	{
		cout<<s[i]<<" ";
	}
	return 0;
 } 
