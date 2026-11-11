#include <iostream>
#include <algorithm>
using namespace std;
#define ll long long
int main(){
	ll a[200005];
	char k[200005];
	ll num=0;
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ll t;
	cin>>t;
	for(ll i = 1; i <= t; i++)
		cin>>a[i]>>k[i];
	ll l=1,r=t;
	while(l<r)
	{
		ll minn=min(a[l],a[r]);
		a[l]-=minn;
		a[r]-=minn;
		if(k[l] != k[r])
			num+=minn;
		if(a[l]==0)
			l++;
		if(a[r]==0)
			r--;
	}
	cout<<num;
	return 0;
}
