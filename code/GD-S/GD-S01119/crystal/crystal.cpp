#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
const ll N=1e6+10;
const ll M=3050;
ll n,m;
ll ans;
ll a[N];
void dfs(ll idx,ll use,ll a[])
{
	if(use>m)return ;
	if(idx>n)
	{
		if(use<=m)
		{
//			sort(a+1,a+n+1);
//			for(ll i=1;i<=n;i++)
//			{
//				cout<<a[i]<<' ';
//			}
//			cout<<'\n';
			ll flag=0;
			for(ll i=1;i<n;i++)
			{
				if(a[i]==a[i+1])
				{
					flag++;
					ans=max(ans,flag+1);
					
				}
				else 
				{
					flag=0;
				}
			}
			ans=max(ans,flag+1);
		}
		return;
	}
	dfs(idx+1,use,a);
	for(ll i=1;i<=m;i++)
	{
		a[idx]+=i;
		dfs(idx+1,use+i,a);
		a[idx]-=i;
	}
	
}
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(ll i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	if(n<=5000)
	{
		sort(a+1,a+n+1);
		dfs(1,0,a);
		cout<<ans;
	}
	else
	{
		ll flag1=1;
		for(ll i=1;i<=n;i++)
		{
			if(a[i]!=i)
			{
				flag1=0;
			}
		}
		//A
		if(flag1==1)
		{
			ll need=0;
			for(ll i=n;i>=1;i--)
			{
				need=ceil((1+i)*i*1.0/2.0);
//				cout<<need<<' '<<i<<'\n';
				if(need<=m)
				{
					cout<<i;
					return 0;
				}
			}
		}
		else
		{
			ll cha=a[2]-a[1];
			ll need=0;
//			cout<<cha<<'\n';
			for(ll i=n;i>=1;i--)
			{
				ll wei=a[i]-a[1];
//				cout<<wei<<'\n';
				need=ceil((cha+wei)*i*1.0/2.0);
//				cout<<need<<' '<<i<<'\n';
				if(need<=m)
				{
					cout<<i;
					return 0;
				}
			}
		}
	}
	return 0;
}
