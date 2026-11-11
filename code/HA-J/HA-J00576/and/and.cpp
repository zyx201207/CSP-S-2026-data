#include<bits/stdc++.h>
using namespace std;
int n,m,a[200005],ans=-1;
bool f[200005];
void dfs(int k,int o,int l)
{
	if(o<=ans) return;
	if(n-l<m-o) return;
	if(k==m)
	{
		ans=o;
		return;
	}
	for(int i=l+1;i<=n;i++)
	{
		if(f[i]==0)
		{
			f[i]=1;
			dfs(k+1,o&a[i],i);
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
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++)
	{
		f[i]=1;
		dfs(1,a[i],i);
		f[i]=0;
	}
	cout<<ans;
	return 0;
}
