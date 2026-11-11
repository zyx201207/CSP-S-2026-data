#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N=5e5+5;
ll a[N];
int n;
ll m;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		scanf("%lld",&a[i]);
	sort(a+1,a+n+1);
	int l=1,r=0,ans=0;
	while(r<n)
	{
		r++;
		ll x=(ll)(r-l)*(a[r]-a[r-1]);
		if(m>=x)
			m-=x;
		else
		{
			while(m<x&&l<r)
			{
				m+=a[r]-a[l];
				l++;
			}
			if(m>=x)
				m-=x;
		}
		if(r-l+1>ans)
			ans=r-l+1;
	}
	cout<<ans;
	return 0;
}
