#include<bits/stdc++.h>
using namespace std;
int n,m,a[500001],b[300001],zm[500001],w[300001],z;
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	  cin>>a[i];
	for(int i=1;i<=n;i++)
	{
		z=0;
		for(int j=i;j<=n;j++)
		{
			if(w[a[j]]!=0)
			{
				for(int k=w[a[j]];k<=z;k++)
				  zm[k]==0;
				z=z-(z-w[a[j]]+1);
			}
			zm[++z]=a[j];
			w[a[j]]=z;
		}
		for(int j=i;j<=z;j++)
		{
			 b[zm[j]]++;
		}
		for(int k=1;k<=z;k++)
		  zm[k]=0;
		for(int k=1;k<=m;k++)
		  w[k]=0;
	}
	for(int i=1;i<=m;i++)
	  cout<<b[i]<<" ";
	return 0;
}
