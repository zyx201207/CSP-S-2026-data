#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],b[300005],f[300005],d[500005],ans[300005],y[300005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		b[a[i]]++;
	}
	for(int i=1;i<=n;i++)
	{
		memset(f,0,sizeof(f));
		memset(d,0,sizeof(d));
		for(int j=i;j<=n;j++)
		{
			if(f[a[j]]==0)f[a[j]]=j;
			else
			{
				d[f[a[j]]]++,d[j]--;
				f[a[j]]=j;
			}
		}
		for(int j=1;j<=m;j++)y[j]=b[j];
		for(int j=i;j<=n;j++)
		{
			d[j]=d[j-1]+d[j]; 
			if(d[j]>0)y[a[j]]--;
		}
		for(int j=1;j<=m;j++)if(y[j]>0)ans[j]++;
		b[a[i]]--;
	}
	for(int i=1;i<=m;i++)printf("%d ",ans[i]);
	return 0;
} 
