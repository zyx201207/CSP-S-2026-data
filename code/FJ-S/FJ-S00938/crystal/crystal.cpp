#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m,ans,sum,a[500001],l=1,r=1;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	for(ll i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	sum=a[2]-a[1],ans=1;
	for(ll i=2;i<=n;i++)
	{
		r++;
		sum+=(a[i]-a[i-1])*(r-l);
		while(sum>m)
		{
			sum-=(a[r]-a[l]);
			l++;
		}
		ans=max(ans,r-l+1);
	}
	cout<<ans<<endl;
	return 0;
}
