#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
bool check(ll i)
{
	while(i)
	{
		if(i%2==0) return 0;
		i/=2;
	}
	return 1;
}
bool cmp(ll x,ll y)
{
	return x>y;
}
ll ans=(1<<30)-1ll,a[223456],n,m;
bool checka(){
	for(ll i=1;i<=n;i++)
	{
		if(!check(a[i])) return 0;
	}
	return 1;
}
bool checkk(){
	for(ll i=1;i<=n;i++)
	{
		if(a[i]!=n-i) return 0;
	}
	return 1;
}
void dfs(ll cur,ll cnt,ll sum)
{
	if(cnt>m) return ;
	if(cur>n)
	{
		if(cnt==m) ans=max(ans,sum);
		return ;
	}
	dfs(cur+1,cnt+1,sum&a[cur]);
	dfs(cur+1,cnt,sum);
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
    for(ll i=1;i<=n;i++) scanf("%lld",a+i);
    sort(a+1,a+1+n,cmp);
    if(m==1)
    {
		ans=a[1];
	}
	else if(m==2)
	{
		ans=0;
		for(ll i=1;i<=n;i++)
		{
			for(ll j=i+1;j<=n;j++)
			{
				ans=max(ans,a[i]&a[j]);
			}
		}
	}
	else if(m==n)
	{
		for(ll i=1;i<=n;i++)
		{
			ans&=a[i];
		}
	}
	else if(checka())
	{
		ans=a[m];
	}
	else if(a[1]<=4)
	{
		ll cnt[6]={0};
		for(ll i=1;i<=n;i++)
		{
			cnt[a[i]]++;
		}
		if(cnt[3])
		{
			if(cnt[3]>=m) ans=3;
			else
			{
				if(cnt[2])
				{
					if(cnt[3]+cnt[2]>=m) ans=2;
					else ans=1;
				}
				else ans=1;
			}
		}
		else
		{
			if(cnt[2]>=m)
			{
				ans=2;
			}
			else ans=1;
		}
	}
	else if(checkk())
	{
		ans=a[1];
		for(ll i=2;i<=m;i++)
		{
			ans&=a[i];
		}
	}
	else if(n<=20)
	{
		ans=0;
		dfs(1,0,(ll)(1<<30)-1ll);
	}
	else
	{
		ans=a[1];
		for(int i=2;i<=m;i++)
		{
			ans&=a[i];
		}
	}
	cout<<ans;
	return 0;
}
