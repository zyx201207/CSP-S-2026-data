#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],w[300005],ans[300005];bool v[300005],l;
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]<a[i-1])l=1;
	}
	if(!l)
	{
		for(int i=1;i<=n;i++)ans[a[i]]=i;
		for(int i=1;i<=m;i++)cout<<ans[i]<<' ';
		return 0;
	}
	for(int i=1;i<=n;i++)
	{
		memset(v,0,sizeof(v));
		for(int j=i;j<=n;j++)
		{
			if(v[a[j]])
			{
				for(int k=w[a[j]]+1;k<j;k++)v[a[k]]=0;
				w[a[j]]=j;
			}
			v[a[j]]=1;w[a[j]]=j;
		}
		for(int j=1;j<=m;j++)ans[j]+=v[j];
	}
	for(int i=1;i<=m;i++)cout<<ans[i]<<' ';
	return 0;
}
