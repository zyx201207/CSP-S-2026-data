#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e5+5;
int n,m,a[N],ans;
void dfs(int step,int x,int gs)
{
	if (step>n||gs>=m)
	{
		if (gs==m) ans=max(ans,x);
		return ;
	}
	dfs(step+1,x,gs);
	dfs(step+1,a[step]&x,gs+1);
}
void solve1()
{
	dfs(1,1048575,0);
	cout<<ans;
}
void solve2()
{
	ans=a[1];
	for (int i=2;i<=n;i++)
		ans&=a[i];
	cout<<ans;
}
void solve3()
{
	for (int i=1;i<=n;i++)
		for (int j=i+1;j<=n;j++)
			ans=max(ans,a[i]&a[j]);
	cout<<ans;
}
void solve4()
{
	for (int i=1;i<=n;i++) ans=max(ans,a[i]);
	cout<<ans;
}
signed main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for (int i=1;i<=n;i++)
		cin>>a[i];
	if (n<=20) solve1();
	if (m==n) solve2();
	if (m==2) solve3();
	if (m==1||n>2000) solve4();
	return 0;
 } 
