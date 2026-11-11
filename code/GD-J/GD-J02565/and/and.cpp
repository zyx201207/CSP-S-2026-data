#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=2e5+10;
ll n,m,ans;
ll a[N];
void dfs(ll cnt,ll ii,ll sum)
{
	if(cnt==1) sum=a[ii];
	if(cnt==m) 
	{
		ans=max(ans,sum);
		return;
	}
	for(int i=1;i<=n;i++)
	{
		if(i<=ii) continue;
		dfs(cnt+1,i,sum&a[i]);
	}
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
	dfs(0,0,1);//cnt ii sum
	cout<<ans;
	return 0;
}


