#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const ll N=5e5+10;
ll a[N],b[N],c[N],cnt=0,s=1,ans=0,sum=0,l=0,siz=0;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);
	ll n,m;
	cin>>n>>m;
	for(ll i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	for(ll i=2;i<=n;i++)
	{
		if(a[i]==a[i-1])s++;
		else
		{
			b[++cnt]=s;
			c[cnt]=a[i-1];
			s=1;
		}
	}
	b[++cnt]=s;
	c[cnt]=a[n];
	siz=ans=b[1];
	for(ll r=2;r<=cnt;r++)
	{
		sum+=siz*abs(c[r-1]-c[r]);
		siz+=b[r];
		while(sum>m)
		{
			l++;
			sum-=b[l]*abs(c[l]-c[r]);
			siz-=b[l];
		}
		ll t;
		if(l!=0)t=(m-sum)/abs(c[l]-c[r]);
		ans=max(ans,siz+t);
	}
	cout<<ans;
}
