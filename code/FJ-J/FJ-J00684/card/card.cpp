#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define P 200010
ll aa[P];
ll a[P];
ll b[P];
ll q[P];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	ll n,m;
	cin>>n>>m;
	for(ll i = 1;i<n;i++)
	{
		cin>>aa[i];
	}
	for(ll i = 1;i<=n;i++)
	{
		for(ll j = i;j<=n;j++)
		{
			if(a[aa[j]]==0)
			{
				a[aa[j]] = 1;
				b[aa[j]] = j;
			}
			else if(a[aa[j]]==1)
			{
				for(ll z = b[aa[j]];z<j;z++)
				{
					aa[z] = 0;
				}
				a[aa[j]] = 0;
			}
		}
		for(ll j = 1;j<=m;j++)
		{
			for(ll z = i;z<=n;z++)
			{
				if(aa[z]==j)
				{
					q[j]++;
				}
			}
		}
	}
	for(ll i = 1;i<=m;i++)
	{
		cout<<q[i];
		if(i!=m)
		{
			cout<<" ";
		}
		else
		{
			cout<<endl;
		}
	}
	return 0;
}

