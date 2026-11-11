#include<bits/stdc++.h>
using namespace std;
int n,m,ans[500001],a[500001],b[500001],pr[300001];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	for(int i=0;i<n;i++)
	{
		for(int i=0;i<n;i++)
		{
			b[i]=a[i];
		}
		for(int i=0;i<=m;i++)
		{
			pr[i]=n;
		}
		for(int j=i;j<n;j++)
		{
			if(pr[b[j]]!=n)
				for(int l=pr[b[j]];l<j;l++)
				{
					pr[b[l]]=n;
					b[l]=0;
				}
			if(b[j]!=0)
				pr[b[j]]=j;
		}
		for(int j=i;j<n;j++)
		{
			if(b[j]>0)
			{
				ans[b[j]-1]++;
			}
		}
	}
	for(int i=0;i<m;i++)
	{
		cout<<ans[i]<<" ";
	}
	return 0;
}
