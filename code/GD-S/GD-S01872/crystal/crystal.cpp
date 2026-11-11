#include<bits/stdc++.h>
using namespace std;
#define ll long long 
ll mp[500005];
ll n,mi=9223372036854775800,ma=-9223372036854775800,m;
bool check2(ll x)
{
	ll ans=0,c=mp[x];
	for(int i=1;i<=x;i++)
	{
		ans+=c-mp[i];
	}
	if(ans<=m)
	{
		return 1;
	}
	for(int i=2,j=x+1;j<=n;i++,j++)
	{
		ans-=mp[j-1]-mp[i-1];
		ans+=(x-1)*(mp[j]-mp[j-1]);
		if(ans<=m)
		{
			return 1;
		}
	} 
	return 0;
}
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>mp[i];
		mi=min(mi,mp[i]);
		ma=max(ma,mp[i]);
	}
	sort(mp+1,mp+n+1);
	ll L=1,R=n,ma=-9223372036854775800,ans=0;
//	cout<<check(315274);
	while(L<=R)
	{
		ll mid=(L+R)/2;
		if(check2(mid))
		{
			L=mid+1;
			ans=mid;
		}
		else
		{
			R=mid-1;
		}
	}
	cout<<ans;
	return 0;
}
/*
二分答案 
二分合成数量 ×
二分合成中最大魔法值的下标+结构体+前缀和 × 
二分合成数量+维护一个数组模拟队列 √ 
暴力 当然是滚蛋 
陆佰陆士路T1做了一个多小时
但估计也就只做一个多小时了 
*/
