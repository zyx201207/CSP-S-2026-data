#include<bits/stdc++.h>
using namespace std;
long long t=2e30-1;
long long m,n,a[200010],maxn=-1,sum=t;
void dfs(long long x,long long y,long long w,long long s)
{
	if(x==m+1)
	{
		maxn=max(maxn,s);
		s=t;
		return;
	}
	if(n-y+1<m-w)
	{
		return;
	}
	for(int i=y+1;i<=n;i++)
	{
		dfs(x+1,i,w+1,s&a[i]);
	}
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		maxn=max(maxn,a[i]);
		sum&=a[i];
	}
	if(m==1)
	{
		cout<<maxn;
		return 0;
	}
	maxn=-1;
	dfs(1,0,m,t);
	cout<<maxn;
	return 0;
}
