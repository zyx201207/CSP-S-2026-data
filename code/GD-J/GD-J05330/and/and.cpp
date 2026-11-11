#include<bits/stdc++.h>
using namespace std;
long long n,m,a[200005],ans,cnt,b[200005];
bool d[200005];
void dfs(int k)
{
	if(k>=m)
	{
		cnt=b[0];
		for(int i=1;i<m;++i)
			cnt=cnt&b[i];
		ans=max(ans,cnt);
		return;
	}
	for(int i=1;i<=n;++i)
	{
		if(d[i])continue;
		b[k]=a[i];
		d[i]=1;
		dfs(k+1);
		d[i]=0;
	}
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;++i)cin>>a[i];
	if(m==n)
	{
		ans=a[1];
		for(int i=2;i<=n;++i)
		{
			ans&=a[i];
		}
	}
	else if(m==n-1)
	{
		ans=a[1];
		cnt=a[2];
		for(int i=2;i<=n;++i)
		{
			ans&=a[i];
		}
		for(int i=1;i<n;++i)
		{
			cnt&=a[i];
		}
		ans=max(ans,cnt);
	}
	else dfs(0);
	cout<<ans;
	return 0;
}
