#include <bits/stdc++.h>
using namespace std;
int n,m,a[200005],f[100005],ans[3005],sum;
int l[200005],r[200005],num[100005];
void aa()
{
	int minn=INT_MAX;
	for(int i=1;i<=n;i++)
	{
		r[a[i]]=i;
		num[a[i]]++;
		minn=min(minn,a[i]);
	}
	for(int i=n;i>=1;i--)
	{
		l[a[i]]=i;
	}
	for(int i=1;i<=m;i++)
	{
		if(num[i]%2==1)
		{
			ans[i]=l[i]+num[i]-1;
		}
		else
		{
			ans[i]=l[i]+num[i]-1;
		}
		cout<<ans[i]<<' ';
	}
	
}
void bb()
{
	for(int i=1;i<=n;i++)
	{
		for(int j=i;j<=n;j++)
		{
			if(f[a[j]]==0)
			{
				f[a[j]]=j;
			}
			else
			{
				for(int k=f[a[j]];k<=j;k++)
				{
					f[a[k]]=0;
				}
				f[a[j]]=j;
			}
		}
		for(int k=1;k<=m;k++)
		{
			if(f[k])ans[k]++;
			f[k]=0;
		}
	}
	for(int i=1;i<=m;i++)
	{
		cout<<ans[i]<<' ';
	}
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		
	}
	for(int i=1;i<n;i++)
	{
		if(a[i+1]>=a[i])sum++;
	}
	if(sum==n-1)
	{
		aa();
	}
	else
	{
		bb();
	}
	
	
	
	return 0;
}
