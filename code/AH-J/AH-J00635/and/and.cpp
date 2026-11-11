#include<bits/stdc++.h>
using namespace std;
int n,m,a[200005],f[200005],maxn=-1,bj[200005],ans=-1;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",a+i);
		f[i]=max(f[i-1],a[i]);
		maxn=max(maxn,a[i]);
	}
	/*for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if(f[j]<(f[j-1]&a[i]))
			{
				f[j]=f[j-1]&a[i];
				bj[j]=bj[j-1]+1;
			}
		}
	}
	for(int i=1;i<=m;i++)
	{
		if(bj[i]==m)
		{
			maxn=max(maxn,f[i]);
		}
	}
	printf("%d",maxn);*/
	if(m==1)cout<<maxn;
	else if(m==2)
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=i+1;j<=n;j++)
			{
				ans=max(ans,a[i]&a[j]);
			}
		}
		cout<<ans;
	}
	else if(m==n)
	{
		ans=a[1];
		for(int i=1;i<=n;i++)
		{
			ans&=a[i];
		}
		cout<<ans;
	}
	return 0;
}
