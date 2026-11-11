#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll INF=5e5+7;
ll a[INF];
ll n,m;
ll ans[INF];
int t[INF];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	ll k=m;
	while(k--)
	{
		stack<ll> q;
		for(int i=n-k-1;i<=n;i++)
		{
			q.push(a[i]);
			t[a[i]]++;
			if(t[a[i]]==2)
			{
				while(q.top()!=a[i])
				{
					q.pop();
				}
			}
		}
		while(!q.empty())
		{
			ans[q.top()]++;
			q.pop();
		}
	}
	for(int i=1;i<=m;i++)
	{
		cout<<ans[i]<<' ';
	}
	return 0;
}
