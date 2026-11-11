#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=2e5+10;
ll n,l,r,z;
struct iv{
	ll sum;
	char s;
}a[N];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(ll i=1;i<=n;i++)cin>>a[i].sum>>a[i].s;
	l=1;
	r=n;
	while(l<r)
	{
		ll j=min(a[l].sum,a[r].sum);
		if(a[l].s!=a[r].s)
		{
			z+=j;
		}
		a[l].sum-=j;a[r].sum-=j;
		if(a[l].sum==0)l+=1;
		if(a[r].sum==0)r-=1;
	}
	cout<<z;
	return 0;
}
