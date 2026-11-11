//祝__wanghc__、__NightDay__、chen_14514、void_ghost、EternalArcana CSP RP++

//打完这把可以原地退役了... 

#include<bits/stdc++.h>
using namespace std;

#define write ios::sync_with_stdio(0);
#define by cin.tie(0);
#define __wanghc__ cout.tie(0);

#define ll long long

const int N=5e5+10;
ll a[N],num[N];
ll n,m,pre,maxn=0;

inline void run(ll x)
{
	auto cnt=upper_bound(a+1,a+n+1,x);
	
	ll pre=cnt-a-1;
	memset(num,0,sizeof(num));
	for(auto i=1;i<=pre;i++)
		num[i]=num[i-1]+x-a[i];
//	unsigned long long res=0;
//	cout<<pre<<endl;
	for(auto i=1;i<=pre;i++)
	{
		if(pre-i+1<=maxn) break;
		if(num[pre]>m) num[pre]-=num[i];
		else
		{
			maxn=max(maxn,pre-i+1);
			break;
		}
	}
}

int main()
{
	write by __wanghc__
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);

	ll l=0x3f3f3f3f,r=-0x3f3f3f;
	cin>>n>>m;
	bool q=0,qq=0;
	for(ll i=1;i<=n;i++)
	{
		if(a[i]!=i) q=1;
		if(a[i]==a[i-1]+2) qq=1;
		cin>>a[i];
		l=min(l,a[i]),r=max(r,a[i]);
	}
	if(!q)
	{
		int i;
		for(i=1;i<=m;i++)
		{
			if(i*(i+1)/2>=m)
			{
				i--;
				break;
			}
		}
		cout<<i;
		return 0;
	}
	if(!qq)
	{
		int i;
		for(i=1;i<=m;i++)
		{
			if(i*i>m)
			{
				i--;
				break;
			}
		}
		cout<<i+1;
		return 0;
	}
	for(ll i=l;i<=r;i++) run(i);
	cout<<maxn;
	return 0;
}
