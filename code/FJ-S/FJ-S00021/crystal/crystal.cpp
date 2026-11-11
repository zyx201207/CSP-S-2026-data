#include<bits/stdc++.h>
using namespace std;
using ll=long long;
ll n,m,a[5000005];
bool check(ll g)//是否符合条件 
{
	ll wanted=0;
	for(ll i=1;i<g;i++)
	{
		wanted+=a[g]-a[i];
	}
	return wanted<=m;
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
	sort(a+1,a+n+1);
	if(m==0)
	{
		ll l_x=0,maxn=-1e15;
		for(ll i=1;i<=n;i++)
		{
			if(i==n||a[i]!=a[i+1])
			{
				maxn=max(l_x,maxn);
				l_x=1;
			}
			else
			{
				l_x++;
			}
		}
		cout<<maxn;
		return 0;
	}
	
	int l=1,r=n;
	while(l<r)//最后一个符合 
	{
		ll mid=l+(r-l+1)/2;//mid是下标！！！
		if(check(mid)) l=mid;
		else r=mid-1; 
	}
	cout<<l;
	return 0;
}
