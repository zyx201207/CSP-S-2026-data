#include<bits/stdc++.h>
using namespace std;
long long a[300006],b[300006],f[300006];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	long long n,m,i,j,k;
	cin>>n>>m;
	for(i=1;i<=n;i++)
		cin>>a[i];
	for(i=1;i<=n;i++)
	{
		memset(f,0,sizeof(f));
		for(j=i+1;j<=m;j++)
		{
			if(f[a[j]])
			{
				for(k=f[a[j]];k<=j;k++)
					f[k]=0;
			}
			f[a[j]]=j;
		}
		for(j=i+1;j<=m;j++)
		{
			if(f[j])
				b[a[j]]++;
		}
	}
	for(i=1;i<=m;i++)
		cout<<b[i]<<" ";
	return 0;
}