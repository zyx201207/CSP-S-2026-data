#include<bits/stdc++.h> 
using namespace std;
long long n,m,a[500005],pg[500005],ans[300005],k1,k;
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}long long f=a[m];bool fl=0;
	
	for(int i=1;i<=n;i++)
	{
		k=0;
		for(int j=i;j<=n;j++)
		{
			fl=0; 
			for(int x=1;x<=k;x++)
			{
				if(pg[x]==a[j]&&fl==0)
				{
					fl=1;
					k1=x;
				}if(fl)
				{
					pg[x]=0;
				}
			}if(fl)
			{
				pg[k1]=a[j];
				k=k1;
			}else
			{
				k++;
				pg[k]=a[j];
			}
		}for(int x=1;x<=k;x++)
		{
			ans[pg[x]]++;
			pg[x]=0;
		}
	}
	for(int i=1;i<=m;i++)
	{
		cout<<ans[m]<<" ";
	}
	return 0;
}
