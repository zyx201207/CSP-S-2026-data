#include<bits/stdc++.h>
using namespace std;

int n,m;
int ar[600000],br[400000]={0},l=1;
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++)
	{
		cin>>ar[i];
		if(ar[i]>ar[i-1])
		{
			l=0;
		}
	}
	if(l==1)
	{
		for(int i=1;i<=m;i++)
		{
			cout<<n<<" ";
		}
		return 0;
	}
	for(int i=0;i<n;i++)
	{
		int cr[600000]={0},dr[400000]={0};
		for(int j=0;j<n;j++)
		{
			if(j+i>=n)break;
			cr[j]=ar[j+i];
			for(int k=0;k<j;k++)
			{
				if(cr[k]==cr[j])
				{
					for(int k=0;k<j;k++)
					{
						cr[k]=0;
						break;
					}
				}
			}

		}
		for(int j=0;j<n;j++)
		{
			dr[ar[j]]=1;
		}
		for(int j=1;j<=m;j++)
		{
			br[i]+=ar[i];
		}
	}
	for(int i=1;i<=m;i++)
	{
		cout<<br[i]<<" ";
	}
	return 0;
}
