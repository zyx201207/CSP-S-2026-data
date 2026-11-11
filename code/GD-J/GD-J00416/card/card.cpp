#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],f[300005];
long long ans[300005];
bool ff[200005][3005];
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	scanf("%d%d",&n,&m);
	bool gg=1;
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		if(a[i]<a[i-1])
		{
			gg=0;
		}
	}
	if(gg==1)
	{
		for(int i=1;i<=n;i++)
		{
			ans[a[i]]++;
		}
		for(int i=1;i<=m;i++)
		{
			ans[i]=ans[i-1]+ans[i];
		}
		for(int i=1;i<=m;i++)
		{
			printf("%lld ",ans[i]);
		}
		return 0;
	}
	for(int i=n;i>=1;i--)
	{
		if(f[a[i]]==0)
		{
			f[a[i]]=i;
		}
		for(int j=1;j<=m;j++)
		{
			ff[i][j]=ff[f[a[i]]+1][j];
			if(ff[i][j]==1)ans[j]++;
		}
		if(ff[i][a[i]]==0)
		{
			ans[a[i]]++;
			ff[i][a[i]]=1;
		}
	}
	for(int i=1;i<=m;i++)
	{
		printf("%lld ",ans[i]);
	}
	
	return 0;
}
