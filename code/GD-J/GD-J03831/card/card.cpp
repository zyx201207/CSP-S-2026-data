#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10,M=3e5+10;
int a[N],p[N],ans[M],k;
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);
	int n,m,i,j,x;
	cin>>n>>m;
	for(i=1;i<=n;i++) cin>>a[i];
	if(n>500)
	{
		for(i=1;i<=n;i++)
		{
			memset(p,0,sizeof(p));
			for(j=i;j<=n;j++)
			{
				x=lower_bound(p+1,p+k+1,a[j])-p;
				if(p[x]==a[j]) k=x-1;
				p[++k]=a[j];
			}
			for(j=1;j<=k;j++) ans[p[j]]++;
		}
		for(i=1;i<=m;i++) cout<<ans[i]<<' ';
		return 0;
	}
	for(i=1;i<=n;i++)
	{
		memset(p,0,sizeof(p));
		for(j=i;j<=n;j++)
		{
			for(x=1;x<=k;x++)
				if(p[x]==a[j])
					k=x-1;
			p[++k]=a[j];
		}
		for(j=1;j<=k;j++) ans[p[j]]++;
	}
	for(i=1;i<=m;i++) cout<<ans[i]<<' ';
	return 0;
}
