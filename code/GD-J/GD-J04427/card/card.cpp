#include<bits/stdc++.h>
using namespace std;
int a[500005];
int ans[300005];
int b[300005];
int n,m;
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	bool f=1;
    for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i-1]>a[i]) f=0;
	}
	if(f==1)
	{
		for(int i=1;i<=n;i++)
		{
			ans[a[i]]+=i;
		}
		for(int i=1;i<=m;i++)
		{
			cout<<ans[i]<<' ';
		}
		return 0;
	}
	for(int i=1;i<=n;i++)
	{
		for(int k=1;k<=m;k++) b[k]=0;
		for(int j=i;j<=n;j++)
		{
			if(b[a[j]]==0) b[a[j]]=j;
			else
			{
				for(int k=b[a[j]];k<j;k++)
				{
					b[a[k]]=0;
				}
				b[a[j]]=j;
			}
		}
		for(int k=1;k<=m;k++) if(b[k]>0) ans[k]++;
	}
	for(int i=1;i<=m;i++)
	{
		cout<<ans[i]<<" ";
	}
}
