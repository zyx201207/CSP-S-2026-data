#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
ll n,m;
ll a[500010];
ll total=0;
ll cnt=0;
ll vis;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(ll i=1;i<=n;i++)
	{
		cin>>a[i];
		total+=a[i];
	}
	sort(a+1,a+n+1);
	cnt=n;
	for(ll i=0;i<=n;i++)
	{
		if((m+total)/(n-i)>=a[n-i])
		{
			vis=n-i;
			break;
		}
		else
		{
			total-=a[n-i];
			cnt--;
		}
	}
	for(ll i=vis;i<=n;i++)
	{
		if(a[vis]==a[i+1])cnt++;
		else break;
	}
	cout<<cnt;
	return 0;
}
