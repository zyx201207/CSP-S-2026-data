#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	long long m,n;
	cin>>m>>n;
	long long a[m+5],b[m+5]={0},c[m+5]={0},f[m+5]={0},ans[n+5]={0};
	for(int i=1;i<=m;i++)
	{
		cin>>a[i];
	 } 
	 for(int i=1;i<=m;i++)
	 {
	 	for(int j=i;j<=m;j++)
	 	{
	 		b[j]=a[j];
	 		c[b[j]]++;
	 		if(c[b[j]]>1)
	 		{
	 			for(int z=f[b[j]];z<j;z++)
	 			{
	 				c[b[z]]--;
	 				b[z]=0;
				}
			}
			f[b[j]]=j;
		}
		for(int z=1;z<=n;z++)
		{
			if(c[z]>0)
			{
			 	ans[z]++;
			}
			c[z]=0;
		}
	 }
	 for(int i=1;i<=n;i++)
	 {
	 	cout<<ans[i]<<" ";
	 }
} 
