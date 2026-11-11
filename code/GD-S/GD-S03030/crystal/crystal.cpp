#include<bits/stdc++.h>
using namespace std;
int n,maxn,cnt;
long long m,a[500005],sum[500005],c;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n;i++)
	{
		c=m;
		cnt=0;
		for(int j=i-1;j>=1;j--)
		{
			if(a[i]-a[j]<=m)
			{
				c-=a[i]-a[j];
				cnt++;
			}
			else
			{
				break;
			}
		}
		maxn=max(maxn,cnt);
	}
	cout<<maxn+1;
	return 0; 
} 
