#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
int n,m,a[500005],ans[300005];

int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++)
	{
		int f[300005]={};
		for(int j=1;j<=n;j++)
		{
			if(f[a[j]])
			{
				for(int k=f[a[j]];k<j;k++)
				{
					//ans[a[k]]--;
					f[a[k]]=0;
				}
				
			}
			f[a[j]]=j;
			
		}
		for(int k=1;k<=m;k++)if(f[k])ans[k]++;
	}
	for(int i=1;i<=m;i++)cout<<ans[i]<<' ';
}
