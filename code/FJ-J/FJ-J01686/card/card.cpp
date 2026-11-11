#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],pos[300005],sum[300005],cnt[300005];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n;i++)
	{
		int pos1=0;
		for(int j=i;j<=n;j++)
		{
			pos1++;
			if(pos[a[j]]!=0&&pos[a[j]]<pos1)
			{
				pos1=pos[a[j]];
			}
			
			pos[a[j]]=pos1;
			cnt[pos1]=a[j];
		
		}
		for(int j=1;j<=pos1;j++)
		{
			sum[cnt[j]]++;
		}
		for(int j=1;j<=m;j++)
			pos[j]=0;
		
		
	}
	for(int i=1;i<=m;i++)
	{	
		cout<<sum[i]<<" ";
	}



	return 0; 
}
