#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const ll MAXN=5e5+5;

ll n,m,ls[MAXN],cnt=1;

int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(ll i=1;i<=n;i++)
	{
		cin>>ls[i];
	}
	sort(ls+1,ls+n+1);
	if(n%2==1)
	{
		ll k=(n+1)/2;
		ll pri=0;
		for(ll i=(n-1)/2;i>=1;i--)
		{
			if(pri+ls[k]-ls[i]<=m)
			{
				cnt++;
				pri+=ls[k]-ls[i];
			}
			else
			{
				break;
			}
		}
		cout<<cnt;
	}
	else
	{
		ll k=n/2;
		ll pri=0;
		for(ll i=(n-2)/2;i>=1;i--)
		{
			if(pri+ls[k]-ls[i]<=m)
			{
				cnt++;
				pri+=ls[k]-ls[i];
			}
			else
			{
				break;
			}
		}
		cout<<cnt;
	}
	return 0;
}
