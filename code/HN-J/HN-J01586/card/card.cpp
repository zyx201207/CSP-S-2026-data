#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m;
int a[500005],d[500005],p=1,s[300005],sum[300005],q;
signed main( )
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	while(n--)
	{
		for(int i=1;i<=m+1;i++)
		{
			s[i]=0;
			d[i]=0;
		}
		p=1;
		for(int i=n+1;i>=1;i--)
		{
			if(s[a[i]]+1>1)
			{
				for(int j=1;j<=p;j++)
				{
					if(d[j]==a[i])
					{
						q=j;
						break;
					}
				}
				for(int j=q;j<=p;i++)d[j]=0;
				p=1;
				d[1]=a[i];
			}
			else
			{
				p++;
				d[p]=a[i];
				s[a[i]]++;
			}
		}
		for(int i=1;i<=m;i++)sum[i]+=s[i];
	}
	for(int i=1;i<=m;i++)cout<<sum[i]<<" ";
	return 0;
}

