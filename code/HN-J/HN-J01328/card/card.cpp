#include<bits/stdc++.h>
using namespace std;
int n,m,x,ans[300010],f[300010],a[500010];
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(f[a[i]]==0)
		f[a[i]]=i;
	}
	for(int t=1;t<=n;t++)
	{
		for(int i=t;i<=n;i++)
		{
		    int sum=a[i];
		    if(f[sum]!=i)
		    {
		    	for(int k=f[sum];k<=i-1;k++)
		    	{
		    		ans[a[k]]--;
				}
				f[sum]=i;
			}
		}
		for(int j=t;j<=n;j++)
		{
			ans[j]++;
		}
	}
	for(int i=1;i<=m;i++)
	cout<<ans[i]<<" ";
	return 0;
}
