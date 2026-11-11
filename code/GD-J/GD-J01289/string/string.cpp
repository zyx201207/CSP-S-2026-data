#include<bits/stdc++.h>
using namespace std;
using ll=long long;

const ll N=2e5+10;
ll n,ans,a[N];
char b[N];

void solve()
{
	cin>>n;
	for(ll i=1;i<=n;i++) cin>>a[i]>>b[i];
	
	ll l=1,r=n;
	while(l<r)
	{
		if(a[l]>a[r])
		{
			if(b[l]!=b[r])
			{
				ans+=a[r];
				a[l]-=a[r--];
			}
			else a[l]-=a[r--];
		}
		else
		{
			if(b[l]!=b[r])
			{
				ans+=a[l];
				a[r]-=a[l++];
			}
			else a[r]-=a[l++];
		}
	}
	cout<<ans;
}

int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	solve();
	return 0;
}
