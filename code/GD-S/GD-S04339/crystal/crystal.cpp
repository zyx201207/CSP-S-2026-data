#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m,a[500005],ans;
vector<int>v;
ll check(ll t,int x)
{
	ll sum=m,cnt=0;
	for(int i=x;i>=1;i--)
	{
		if(a[i]>t)
			continue;
		if(sum>=(t-a[i]))
			sum-=(t-a[i]),cnt++;
		else 
			break;
	}
	return cnt;
}
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++)
	{
		ll t=check(a[i],i);
		if(t>=ans)
		{
			if(t>ans)
				ans=t,v.clear();
			v.push_back(i);
		}
	}
	for(int x:v)
		for(int i=a[x-1]+1;i<a[x];i++)
			ans=max(ans,check(i,x));
	cout<<ans;
}
/*
5 5
1 2 4 8 9

5 8
-3 -1 2 2 7
*/
