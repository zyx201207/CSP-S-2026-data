#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m;
const int maxn=10000000;
ll a[maxn];
ll b[maxn];
ll s[maxn];
ll getnum(ll place)
{
	ll getm=(place-1)*a[place]-s[place-1];
	if(getm<=m) return place;
	ll l=1;
	ll r=place;
	ll val=a[place];
	ll mid;
	while(l<r)
	{
		mid=(l+r)/2;
		if(getm-mid*val+s[mid]>m)
		{
			l=mid+1;
		}
		else if(getm-mid*val+s[mid]==m)
		{
			l=mid+1;
			break;
		}
		else r=mid;
	}
	return place-l;
}
int main(){

    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout); 
	cin>>n>>m;
	for(ll i=1;i<=n;i++)
	{
		cin>>a[i];
		s[i]=s[i-1]+a[i];
	}
	sort(a+1,a+n+1);
	for(ll i=1;i<=n;i++)
	{
		b[i]=getnum(i);
	}
	sort(b+1,b+n+1);
	cout<<b[n];
    return 0;

 
} 
