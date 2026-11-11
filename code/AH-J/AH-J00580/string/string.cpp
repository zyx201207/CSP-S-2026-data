#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=2e5+5;
ll n,a[N],ans;
char c[N];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie();
	cout.tie();
	cin>>n;
	for(ll i=1;i<=n;i++) cin>>a[i]>>c[i],ans+=a[i];
	ll l=1,r=n,sl=a[1],sr=a[n];
	while(l<r)
	{
		ll t=min(sl,sr);
		if(c[l]==c[r]) ans-=t*2;
		sl-=t,sr-=t;
		if(!sl) sl=a[++l];
		if(!sr) sr=a[--r];
	}
	if(l==r) ans-=min(sl,sr);
	cout<<ans/2;
}
