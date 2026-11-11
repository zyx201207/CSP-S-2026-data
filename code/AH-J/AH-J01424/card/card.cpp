#include<bits/stdc++.h>
using namespace std;
int a[500005],b[500005],c[300005];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=0;i<n;i++) cin>>a[i];
	for(int i=0;i<n;i++)
	{
		for(int s=0;s<n;s++) b[s]=0;
		for(int j=i;j<n;j++)
		{
			b[j]=a[j];
			for(int k=i;k<j;k++)
			{
				if(b[j]==b[k])
				{
					for(int l=k+1;l<=j;l++)
					{
						b[l]=0;
					}
					break;
				}
			}
		}
		for(int k=1;k<=m;k++)
		{
			for(int j=i;j<n;j++)
			{
				if(k==b[j])
				c[k]++;
			}
		}
	}
	for(int i=1;i<=m;i++)
	{
		cout<<c[i]<<" ";
	}
	return 0;
}
