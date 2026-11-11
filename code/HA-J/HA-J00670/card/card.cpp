#include<bits/stdc++.h>
using namespace std;
long long a[500010],ans[300010],o[500010];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	long long n,m,i,j,k,l;
	cin>>n>>m;
	for(i=1;i<=n;i++)
		cin>>a[i];
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
			o[j]=0;
		for(j=i;j<=n;j++)
			for(k=j-1;k>=i;k--)
				if(a[j]==a[k]&&o[k]==0)
				{
					for(l=k;l<=j-1;l++)
						o[l]=1;
				}
		for(j=i;j<=n;j++)
			if(o[j]==0)
				ans[a[j]]++;
	}
	for(i=1;i<=m;i++)
		cout<<ans[i]<<" ";
}
