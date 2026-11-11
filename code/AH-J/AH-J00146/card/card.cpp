#include<bits/stdc++.h>
using namespace std;
using ll=long long;
ll a[500005],f[300005],n,m,b[300005],lst[300005];
void so1()
{
	for(ll i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(ll i=1;i<=n;i++)
	{
		ll bt=0;
		fill(lst+1,lst+m+1,-1);
		for(ll j=i;j<=n;j++)
		{
			if(lst[a[j]]==-1)
			{
				b[++bt]=a[j];
				lst[a[j]]=bt;
			}
			else
			{
				for(ll k=lst[a[j]]+1;k<=bt;k++)
				{
					lst[b[k]]=-1;
				}
				bt=lst[a[j]];
			}
		}
		for(ll j=1;j<=bt;j++)f[b[j]]++;
	}
	for(ll i=1;i<=m;i++)cout<<f[i]<<' ';
}
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	so1();
	return 0;
}
