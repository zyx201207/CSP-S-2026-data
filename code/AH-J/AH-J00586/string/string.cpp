#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const ll N=2e5+10;
ll a[N];
char c[N];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);
	ll n,x=0,y=0,t,ans=0,l=1,r;
	char xc,yc;
	cin>>n;
	for(ll i=1;i<=n;i++)cin>>a[i]>>c[i];
	r=t=n;
	while(n--)
	{
		if(x==0)
		{
			x+=a[l];
			xc=c[l++];
		}
		else
		{
			y+=a[r];
			yc=c[r--];
		}
		if(xc!=yc)ans+=min(x,y);
		ll cnt=min(x,y);
		x-=cnt;y-=cnt;
	}
	cout<<ans;
}
