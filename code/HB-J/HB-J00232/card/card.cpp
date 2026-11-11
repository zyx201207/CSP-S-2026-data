#include <bits/stdc++.h>
#define ll long long 
using namespace std;
ll n,m,ans[100005],a[200005],b[200005],p,t;
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(ll i=1;i<=n;i++)
		cin>>a[i];
	for(ll i=1;i<=n;i++)
	{
		p=1;
		for(ll j=i;j<=n;j++)
		{
			t=-1;
			for(ll k=1;k<=p-1;k++)
				if(b[k]==a[j])t=k;
			if(t>-1)p=t+1;
			else b[p++]=a[j];
		}
		for(ll j=1;j<=p-1;j++)
			ans[b[j]]++;
	}
	for(ll i=1;i<=m;i++)
		cout<<ans[i]<<' ';
	return 0;
}

