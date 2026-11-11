#include<bits/stdc++.h>
using namespace std;
using ll=long long;

ll n,m,ls[5000005],mx;

ll bfs(ll j,ll t)
{
	ll a=j-1;
	ll b=j+1;
	while(1)
	{
		if(0<a && ls[j]-ls[a]<ls[b]-ls[j] && t>=ls[j]-ls[a])
		{
			t-=ls[j]-ls[a];
			a--;
		}
		else if(b<=n && t>=ls[b]-ls[j])
		{
			t-=ls[b]-ls[j];
			b++;
		}
		else
		{
			break;
		}
	}
	return b-a-1;
}

int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%d %d",&n,&m);
	for(ll i=1;i<=n;i++)
	{
		cin>>ls[i];
	}
	sort(ls+1,ls+n+1);
	for(ll i=2;i<n;i++)
	{
		ll a=bfs(i,m);
		if(mx<=a)
		{
			mx=a;
		}
	}
	cout<<mx;
	return 0;
}
