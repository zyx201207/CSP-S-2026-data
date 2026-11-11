#include<bits/stdc++.h>
using namespace std;
long long a[200010],out[200010];
long long n,m,ans=INT_MIN;
void dfs(long long u,long long s)
{
	long long i,ns=0;
	if(s>m)
	{
		ns=out[1];
		for(i=2;i<=m;i++)
			ns=ns&out[i];
		ans=max(ans,ns);
		return;
	}
	for(i=u+1;i<=n;i++)
	{
		out[s]=a[i];
		dfs(i,s+1);
	}
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	long long i,j;
	cin>>n>>m;
	for(i=1;i<=n;i++)
		cin>>a[i];
	for(i=0;i<=n-m-2;i++)
		dfs(i,1);
	cout<<ans;
}
