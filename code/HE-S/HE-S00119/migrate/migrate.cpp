#include<bits/stdc++.h>
using namespace std;
long long c,t;
long long n,d;
long long x[500005];
long long minn;
long long ans;
void dfs(long long zb,bool f,long long num)
{
	if(zb==x[n]&&minn==num)
	{
		++ans;
		return ;
	}
	if(zb==x[n]) return;
	if(f)
	{
		zb=x[lower_bound(x+1,x+1+n,zb+d)-x];
		dfs(zb,true,num+1);
	}
	else
	{
		dfs(x[upper_bound(x+1,x+1+n,zb)-x],true,num+1);
		zb=lower_bound(x+1,x+1+n,zb+d)-x;
		dfs(zb,false,num+1);
	}
	return ;
}
void solve()
{
	cin>>n>>d;
	for(int i=1;i<=n;i++) cin>>x[i];
	minn=0;
	long long l=x[1];
	while(l<x[n])
	{
		++minn;
		l=x[lower_bound(x+1,x+1+n,l+d)-x];
	}
	ans=0;
	dfs(1,false,0);
	cout<<(ans+1)*ans/2<<endl;
}
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--)
	{
		solve();
	}
	return 0;
}
