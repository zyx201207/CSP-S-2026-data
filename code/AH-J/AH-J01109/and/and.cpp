#include<bits/stdc++.h>
using namespace std;
long long a[200005],ans=0;
void dfs(int t,int b,int e,long long k)
{
	if(e-b+1<t)return;
	for(int i=b;i<=e;i++)
	{
		long long v=k&a[i];
		if(t>1)dfs(t-1,i,e,v);
		else ans=max(ans,v);
	}
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	if(m!=n-1)
		for(int i=1;i<n;i++)
			dfs(m-1,i+1,n,a[i]);
	else
	{
		for(int i=1;i<=n;i++)
		{
			long long k=-1;
			for(int j=1;j<=n;j++)
			{
				if(j!=i)
				{
					if(k==-1)k=a[j];
					k&=a[j];
				}
			}
			ans=max(ans,k);
		}
	}
	cout<<ans;
	return 0;
}
