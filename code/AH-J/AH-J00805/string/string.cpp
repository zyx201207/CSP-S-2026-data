#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
struct N{
	char a;
	ll b;
}a[223235];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
    ll n,sum=0,suml=0,ans=0;
    cin>>n;
    for(ll i=1;i<=n;i++)
    {
		cin>>a[i].b>>a[i].a;
		sum+=a[i].b;
	}
	ll l=1,r=n;
	while(suml<=sum/2&&l<=r)
	{
		ll j=min(a[l].b,a[r].b);
		suml+=j;
		if(a[r].a!=a[l].a) ans+=j;
		a[l].b-=j;
		a[r].b-=j;
		if(!a[l].b) l++;
		if(!a[r].b) r--;
	}
	cout<<ans;
	return 0;
}
