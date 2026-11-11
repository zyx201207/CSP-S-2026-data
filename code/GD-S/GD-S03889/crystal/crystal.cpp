#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N=5e5+10;

ll n,m;
ll a[N];
ll b[N];

int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin>>n>>m;
	
	int cnt=1;
	int cmp=1;
	
	for(ll i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	
	for(ll i=1;i<=n;i++)
	{
		if(a[i]==a[i+1])
		{
			cnt++;
		}
		else
		{
			cmp=max(cmp,cnt);
			cnt=0;
		}
	}
	
	if(cmp==n)
	{
		cout<<n;
		return 0;
	}
	
	sort(a+1,a+n+1);
	
	b[1]=a[1];
	
	for(ll i=2;i<=n;i++)
	{
		b[i]=b[i-1]+a[i];
	} 
	
	ll ans=cmp; 
	
	for(ll i=2;i<=n;i++)
	{
		if(a[i]*(i-1)-b[i-1]<=m)
		{
			ans=max(ans,i);
		}
		else break;
	}
	
	cout<<ans;
	
	return 0;
}

