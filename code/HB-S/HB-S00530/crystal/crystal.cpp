#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N=5e5+5;
struct idc{
	int id;
	int cnt;
	int pos;
	bool f;
}c[200005];
bool cmp(idc x,idc y)
{
	if(x.cnt==y.cnt)
		return x.id<y.id;
	else
		return x.cnt>y.cnt;
}
ll a[N],cnt[N];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	ll n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	if(m>1e8)
	{
		ll num=0;
		ll sum=0;
		if(n==1)
		{
			cout<<1;
			return 0;
		}
		for(int i=2;i<=n;i++)
		{
			sum+=a[i-1];
			num=(i-1)*a[i]-sum;
			if(num>m)
			{
				cout<<i-1;
				return 0;
			}
		}
		cout<<n;
		return 0;
	}
	else
	{
		for(int i=1;i<=n;i++)
		{
			c[a[i]+100000].cnt++;
			if(!c[a[i]+100000].f)
			{
				c[a[i]+100000].f=1;
				c[a[i]+100000].pos=i;
			}
		}
		for(int i=-100000;i<=100000;i++)
		{
			c[i+100000].id=i;
		}
		sort(c,c+200005,cmp);
		ll ans=-1;
		for(int k=0;k<=2*n;k++)
		{
			if(c[k].cnt==0)
				break;
			ll num=0;
			ll sum=0;
			bool f1=0;
			for(int i=c[k].pos+1;i<=n;i++)
			{
				sum+=a[i-1];
				num=(i-c[k].pos)*a[i]-sum;
				if(num>m)
				{
					ll cans=i-c[k].pos;
					ans=max(ans,cans);
					f1=1;
					break;
				}
				
			}
			if(!f1)
			{
				ans=max(ans,n-c[k].pos+1);
			}	
		}
		
		cout<<ans;
	}
}
