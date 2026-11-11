#include<Bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n,m,a[N],ans;
void dfs(int p,int k,int sum)
{
	if(k>m)
	{
		ans=max(ans,sum);
		return;
	}
	if(p>n) return;
	if(k==1)
	{
		dfs(p+1,k+1,a[p]);
		dfs(p+1,k,sum);
	}
	else
	{
		dfs(p+1,k+1,sum&a[p]);
		dfs(p+1,k,sum);
	}
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	dfs(1,1,0);
	cout<<ans;
}
