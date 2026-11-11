#include <bits/stdc++.h>
using namespace std;
const int N=200005;
long long n,m,a[N],ans,l,r;
void dfs(int i,int m1,long long sum)
{
	if(i+m-m1-1>n)
		return;
	if(m1==m)
	{
		ans=max(ans,sum);
		return;
	}
	dfs(i+1,m1,sum);
	if(sum==0)
	dfs(i+1,m1+1,a[i]);
	else
	dfs(i+1,m1+1,sum&a[i]);
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	dfs(1,0,0);
	cout<<ans;
	return 0;
} 
