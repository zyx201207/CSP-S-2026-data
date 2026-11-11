#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[222222],c,mx;
void dfs(int stp,int c,int as)
{
	if(c==m)
	{
		mx=max(mx,as);
		return;
	}
	if(stp>n) return;
	dfs(stp+1,c,as);
	if(as==-1) dfs(stp+1,c+1,a[stp]);
	else dfs(stp+1,c+1,as&a[stp]);
}
signed main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	if(m==1)
	{
		for(int i=1;i<=n;i++) mx=max(mx,a[i]);
		cout<<mx;
		return 0;
	}
	if(n==m)
	{
		c=a[1];
		for(int i=2;i<=n;i++) c&=a[i];
		cout<<c;
		return 0;
	}
	if(n<=20)
	{
		dfs(1,0,-1);
		cout<<mx;
		return 0;
	}
	if(m==2&&n<=10000)
	{
		for(int i=1;i<n;i++) for(int j=i+1;j<=n;j++) mx=max(mx,a[i]&a[j]);
		cout<<mx;
		return 0;
	}
	if(n>2000)
	{
		for(int i=1;i<=n;i++) mx=max(mx,a[i]);
		cout<<mx;
		return 0;
	}
	return 0;
}
