#include<bits/stdc++.h>
#define ll long long
#define endl '\n';
using namespace std;
const ll maxn=2e6+10;
ll c,t,a[maxn],n,d;
ll v,cnm,nmb,daan=0;
void dfs(ll u,ll ans)
{
	if(u==v&&ans==cnm)
	{
		nmb++;
		return ;
	}
	if(ans>=cnm)	return ;
	for(ll i=u+1;i<=v;i++)
	{
		if(a[u]+d>=a[i])	dfs(i,ans+1);
	}
}
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--)
	{
		daan=0;
		cin>>n>>d;
		for(ll i=1;i<=n;i++)
		{
			cin>>a[i];
		}
		for(ll i=1;i<=n;i++)
		{
			for(ll j=i+3;j<=n;j++)
			{
				ll x=i,cnt=0;
				for(ll k=i+1;k<=j;k++)
				{
					if(a[x]+d<a[k])	x=k-1,cnt++;
				}
				cnt++;
				v=j,cnm=cnt,nmb=0;
				dfs(i,0);
				if(nmb==2)	daan++;
			}
		}
		cout<<daan<<endl;
	}
	return 0;
}
