#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],x,z[500005];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(long long i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(long long i=1;i<=n;i++)   //n¾ÖÓÎÏ· 
	{
		long long ans[500007]={0};
		x=0;
		for(long long j=i;j<=n;j++)   //·ÅÅÆ 
		{
			bool f=0;
			for(long long k=1;k<=x;k++)  //ÕÒ 
			{
				if(ans[k]==a[j]) 
				{
					x=k;
					f=1;
				}
			}
			if(f==0)
			{
				x++;
				ans[x]=a[j];
			}
		}
		for(long long j=1;j<=x;j++)
		{
			z[ans[j]]++;
		}
	}
	for(long long i=1;i<=m;i++)
	{
		cout<<z[i]<<" ";
	}
	return 0;
}
