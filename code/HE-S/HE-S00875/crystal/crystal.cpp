#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll a[500005];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int n;
	ll m;cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	int l=1;ll maxn=1;
	ll sum=0;
	for(int i=2;i<=n;i++)
	{
		while(sum+(i-l)*(a[i]-a[i-1])>m&&l<i)
		{
			sum-=a[i-1]-a[l];l++;
		}
		sum+=(i-l)*(a[i]-a[i-1]);
		maxn=max(maxn,(ll)i-l+1);
	}
	cout<<maxn;
}
