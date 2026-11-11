#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m;
ll a[500005];
ll shu[300005];
ll shui[300005];
int main()
{
 	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(ll i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(ll i=1;i<=n;i++)
	{
		memset(shui,0,sizeof(shui));
		for(ll j=i;j<=n;j++)
		{
			if(shui[a[j]]==0)shui[a[j]]=1;
			else if(shui[a[j]]>0)
			{
				for(ll l=j-1;l>=1;l--)
				{
					if(a[l]==a[j])
					{
						break;
					}
					else
					{
						shui[a[l]]=0;
					}
				}
			}
		 }
		for(ll j=1;j<=m;j++)
		{
			shu[j]+=shui[j];
		  }  
	}
	for(ll j=1;j<=m;j++)
	{
		cout<<shu[j]<<" ";
	}
	return 0;
}
/*
 10 3
3 1 2 1 3 2 3 1 2 1
*/

