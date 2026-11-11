#include <bits/stdc++.h>
using namespace std;
long long n,m,a[200006],ans=-1,vis[200005],maxn=-1;
void dfs(long long k,long long cnt)
{
	if(k>n)	return;
	if(cnt==m)
	{
		long long jia,f=0;
		for(int i = 1;i <= n;i++)
		{
			if(vis[i]==1)
			{
				if(f==0)	jia = a[i];
				else	jia &= a[i];
				f=1;
			} 
		}
		ans = max(ans,jia);
		return;
	}
	if(vis[k]==0)
	{
		vis[k]=1;
		dfs(k+1,cnt+1);
		vis[k]=0;
	}
	dfs(k+1,cnt);
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n >> m;
	long long f = 1,jia[200005];
	jia[1]=2;
	for(int i = 2;i <= n;i++)
	{
		jia[i]=jia[i-1]*2;
	}
	for(int i = 1;i <= n;i++)
	{
		cin >> a[i];
		if(a[i]!=jia[i]-1)	f=0;
		maxn = max(maxn,a[i]);
	}
	if(f)
	{
		cout << a[n-m+1];
		return 0;
	}
	dfs(1,0);
	cout << ans;
	return 0;
}
