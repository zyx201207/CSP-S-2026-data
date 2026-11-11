#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
const ll N=1e6+10;
const ll M=3050;
ll n,m,ans;
ll a[N];
void dfs(ll idx,ll sum,ll choose)
{
	if(choose>m)return;
	if(idx>n)
	{
		if(choose==m)
		{
			ans=max(ans,sum);
		}
		return;
	}
	dfs(idx+1,sum,choose);
	if(choose==0){
		dfs(idx+1,a[idx],choose+1);
//		cout<<a[idx]<<"a ";
	}
	else 
	{
		dfs(idx+1,(sum&a[idx]),choose+1);
//		cout<<sum<<"a ";
	}
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(ll i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	if(m==1)
	{
		ll flag=0;
		for(ll i=1;i<=n;i++)
		{
			flag=max(flag,a[i]);
		}
		cout<<flag;
		return 0;
	} 
	if(m==n)
	{
		ll flag=a[1];
		for(ll i=2;i<=n;i++)
		{
			flag=flag&a[i];
		}
		cout<<flag;
		return 0;
	}
	dfs(1,0,0);
	cout<<ans;
	return 0;
}
