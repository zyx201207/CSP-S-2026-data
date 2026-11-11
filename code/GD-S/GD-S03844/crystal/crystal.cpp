#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
const ll N=5e5+5;
ll n,a[N],m,sum,ans=1,d;
bool check(ll x)
{
	for(ll i=1;i+x-1<=n;i++)
	{
		sum=0;
		ll z=a[i+(x/2)]; 
		for(ll j=i;j<=i+x-1;j++)
		{
			sum+=abs(z-a[j]);
		}
		if(sum<=m)
			return 1;
	}
	return 0; 
}
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n >> m;
	for(ll i=1;i<=n;i++)
		cin >> a[i];
	if(n>5000)
	{
		d=a[2]-a[1];
		ll j=1;
	    while(m>=j*d)
	    {
	    	m-=j*d;
	    	j+=2;
		}
		j-=2; 
		if(m==j*d/2);
			j++;
		if(j==0)
		{
			cout << 1 << endl;
			return 0;
		}
		cout << min(n,j) << endl;
		return 0;
	}
	sort(a+1,a+1+n);
	ll l=1,r=n;
	while(l<=r)
	{
		ll mid=(r-l)/2+l;
		if(check(mid))
		{
			l=mid+1;
		    ans=mid;
		}
		else 
		{
			r=mid-1;
		}
	}
	cout << ans << endl;
	return 0;
}
