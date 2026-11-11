#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e5+10;
ll n,m,a[N],ans;
void dfs(ll p,ll sum,ll res)
{
	if(sum==m)
	{
		ans=max(ans,res);
		return;
	}
	if(p>=n+1) return;
	if(sum==0) dfs(p+1,1,a[p]);
	else dfs(p+1,sum+1,res&a[p]);
	dfs(p+1,sum,res);
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(ll i=1;i<=n;i++)
		cin>>a[i];
	dfs(1,0,0);
	cout<<ans;
	return 0;
}
