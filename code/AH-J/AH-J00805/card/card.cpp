#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[523456],f[323456];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ll n,m;
	cin>>n>>m;
	//for(ll i=1;i<=m;i++) w[i]=-1;
	for(ll i=1;i<=n;i++)
	{
		scanf("%lld",a+i);
		/*
		if(w[a[i]]==-1) f[i]=-1;
		else
		{
			if(f[w[a[i]]]!=-1) f[i]=-1;
			else f[i]=w[a[i]];
		}
		w[a[i]]=i;
		*/
	}
	for(ll i=1;i<=n;i++)
	{
		deque<ll> dq;
		map<ll,ll> m;
		for(ll j=i;j<=n;j++)
		{
			m[a[j]]++;
			while(m[a[j]]>=2)
			{
				m[dq.back()]--;
				dq.pop_back();
			}
			dq.push_back(a[j]);
		}
		while(!dq.empty())
		{
			f[dq.back()]++;
			dq.pop_back();
		}
	}
	for(ll i=1;i<=m;i++)
	{
		cout<<f[i]<<" ";
	}
	return 0;
}
