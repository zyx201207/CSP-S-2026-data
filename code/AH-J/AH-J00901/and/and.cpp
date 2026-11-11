#include<bits/stdc++.h>
using namespace std;
int a[200005],f[200005],n,m,ma=INT_MIN;
void dfs(int step,int sum,int k)
{
	if(step==m+1)
	{
		ma=max(ma,sum);
		return;
	}
	for(int i=k;i<=n;i++)
	{
		if(f[i]==0)
		{
			f[i]=1;
			dfs(step+1,sum&a[i],i+1);
			f[i]=0;
		}
	}
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	dfs(1,2^30,1);
	cout<<ma;
}
