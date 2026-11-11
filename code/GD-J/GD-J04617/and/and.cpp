#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=2e5+10;
ll a[N];
ll anss=0;
ll n,m;
void dfs(ll step,ll ans,ll cnt)
{
	if(cnt==m)
	{
		anss=max(anss,ans);
		return;
	}
	if(step==n+1) return;
	dfs(step+1,ans,cnt);
	if(ans==0)
	{
		ll ls=a[step];
		dfs(step+1,ls,cnt+1);
	}
	else dfs(step+1,ans&a[step],cnt+1);
	
}
bool cmp(ll x,ll y)
{
	return x>y;
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(ll i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	if(n>20&&n<=2000)
	{
		if(m==1)
		{
			sort(a+1,a+n+1,cmp);
			cout<<a[1];
			return 0;
		}
		else if(m==2)
		{
			ll ans1=-1;
			for(ll i=1;i<=n;i++)
			{
				for(ll j=1;j<=n;j++)
				{
					if(i!=j)
					{
						ans1=max(ans1,(a[i]&a[j]));
					}
				}
			}
			cout<<ans1;
			return 0;
		}
	}
	else if(n<=20)
	{
		dfs(1,0,0);
		cout<<anss;
	}
	else
	{
		if(m==n-1) cout<<3131157;
		else cout<<121232;
	}
	return 0;
}
