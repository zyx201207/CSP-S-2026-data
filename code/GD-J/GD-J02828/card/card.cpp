#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500001],b[300001],ids,sum[300001],f[300001];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++)
	{
		memset(f,0,sizeof(f));
		ids=0;
		for(int j=i;j<=n;j++)
		{
			ids++;
			b[ids]=a[j];
			if(f[a[j]]!=0&&b[f[a[j]]]==a[j])ids=f[a[j]];
			for(int k=ids;k<=m+1;k++)f[k]=0;
			for(int k=1;k<=ids;k++)f[b[k]]=k;
		}
		for(int k=1;k<=ids;k++)sum[b[k]]++;
	}
	for(int i=1;i<=m;i++)cout<<sum[i]<<" ";
	return 0;
}

