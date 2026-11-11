#include <bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n,m;
long long a[N];
bool vis[N];
long long ans=0;
void dfs(int u)
{
	if(u>m)
	{
		long long res;
		for(int i=1;i<=n;i++)
		{
			if(vis[i])
			{
				res=a[i];
				break;
			}
		}
		for(int i=1;i<=n;i++)
		{
			if(vis[i]) res=(res&a[i]);
		}
		//cout <<res<<" ";
		ans=max(ans,res);
		//cout <<"ok";
		return ;
	}
	for(int i=1;i<=n;i++)
	{
		if(!vis[i])
		{
			vis[i]=1;
			dfs(u+1);
			vis[i]=0;
		}
	}
}
void solve1()
{
	dfs(1);
	cout <<ans;
	exit(0);
}
void solve2()
{
	for(int i=1;i<=n;i++) ans=max(ans,a[i]);
	cout <<ans;
	exit(0);
}
void solve3()
{
	for(int i=1;i<=n;i++)
	{
		for(int j=i+1;j<=n;j++)
		{
			long long res=(a[i]&a[j]);
			ans=max(ans,res);
		}
	}
	cout <<ans;
	exit(0);
}
void solve4()
{
	ans=a[1];
	for(int i=1;i<=n;i++) ans&=a[i];
	cout <<ans;
	exit(0);
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","r",stdout);
	cin >>n>>m;
	for(int i=1;i<=n;i++) cin >>a[i];
	if(n<=2000 && m==2) solve3();
	if(n<=20) solve1();
	if(m==1) solve2();
	if(n<=2000 && m==n) solve4();
	return 0;
}
/*
4 2
3 15 12 12
*/
