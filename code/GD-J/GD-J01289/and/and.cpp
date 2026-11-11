#include<bits/stdc++.h>
using namespace std;
using ll=long long;

const ll N=2e5+10;
ll n,m,id,ans=-1e18,a[N];

void dfs(ll num,ll k,ll i)//num当前的值 k已经选择的数量 i要考虑是否选择的数的下标
{
	if(i>n || k>=m)
	{
		if(k==m) ans=max(ans,num);
		return;
	}
	dfs(num,k,i+1);
	if(k<m) dfs(num&a[i],k+1,i+1);
	return;
}
void solve()
{
	cin>>n>>m;
	for(ll i=1;i<=n;i++) cin>>a[i];
	
	if(n==m)
	{
		ans=(1<<31)-1;
		for(ll i=1;i<=n;i++) ans&=a[i];
		cout<<ans;
		return;
	}
	
	if(n>2)
	{
		sort(a+1,a+n+1);
		cout<<a[n-m+1];
		return;
	}
	
	dfs((1<<31)-1,0,0);
	cout<<ans;
	return;
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	solve();
	return 0;
} 
