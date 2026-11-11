#include<bits/stdc++.h>
using namespace std;
const int N=500100;
int n,m,a[N],c[N],k,cnt[N];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
	}
	if(n<=500)
	{
		for(int i=1;i<=n;i++)
		{
			k=0;
			for(int j=i;j<=n;j++)
			{
				for(int z=1;z<=k;z++)
					if(c[z]==a[j]) k=z-1;
				c[++k]=a[j];
			}
			for(int j=1;j<=k;j++)
				cnt[c[j]]++;
		}
		for(int i=1;i<=m;i++)
			cout<<cnt[i]<<' ';
	}
	else
	{
		for(int i=1;i<=m;i++)
		{
			cnt[a[i]]++;
		}
		for(int i=1;i<=m;i++)
			cout<<cnt[i]<<' ';
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
