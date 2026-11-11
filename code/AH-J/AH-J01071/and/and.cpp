#include<bits/stdc++.h>
using namespace std;
long long maxn=0,n,m;
long long a[200005];
void dfs(long long k,long long l,long long sum)
{
	if(l==m+1)
	{
		maxn=max(maxn,sum);
		return;
	}
	if(k==n+1) return;
	if(sum!=0) dfs(k+1,l+1,sum&a[k]);
	if(sum==0) dfs(k+1,l+1,a[k]);
	dfs(k+1,l,sum);
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	if(n<=20)
	{
		for(int i=1;i<=n;i++) cin>>a[i];
		dfs(1,1,0);
		cout<<maxn;
		return 0;
	}
	long long maxna=0;
	for(int i=1;i<=n;i++) 
	{
		cin>>a[i];
		maxna=max(maxna,a[i]);
		
	}
	cout<<maxna;
	return 0;
}
