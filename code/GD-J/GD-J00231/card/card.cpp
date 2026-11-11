#include<bits/stdc++.h>
using namespace std;
long long n,m,a[1000005],sum[1000005],cx[1000005],wz[1000005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n;i++)
	{ 
		for(int j=i;j<=a[i];j++)
		{
			if(cx[a[j]]==0)
			{
				cx[a[j]]=1;
				wz[a[j]]=j;
			}
			else
			{
				for(int z=wz[a[j]];z<j;z++)
				{
					cx[a[z]]=0;
				}
				wz[a[j]]=j;
			}
		}
		for(int j=1;j<=n;j++)
		{
			if(cx[j]==1)
			{
				sum[j]++;
			}
		}
		for(int j=1;j<=1000005;j++)
		{
			cx[i]=0,wz[i]=0;
		}
	}
	for(int i=1;i<=n;i++)
	{
		cout<<sum[i]<<" ";
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
