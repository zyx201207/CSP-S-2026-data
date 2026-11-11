#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const ll N=5e5+10;
ll dp[N],a[N],b[N],c[N],l[N],r[N],ans[N],sum=0;
priority_queue<ll>pq;
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);
	ll n,m;
	cin>>n>>m;
	for(ll i=1;i<=n;i++)cin>>a[i];
	for(ll i=1;i<=n;i++)
	{
		if(b[a[i]])l[i]=b[a[i]];
		else l[i]=-1;
		b[a[i]]=i;
	}
	for(ll i=n;i>=1;i--)
	{
		if(c[a[i]])r[i]=c[a[i]];
		else r[i]=-1;
		c[a[i]]=i;
	}
	dp[1]=1;
	for(ll i=2;i<=n;i++)
	{
		if(r[i-1]==-1)dp[i]+=dp[i-1];
		if(l[i]!=-1)dp[i]+=dp[l[i]];
		dp[i]++;
	}
	for(ll i=n;i>=1;i--)
	{
		ans[a[i]]+=i;
		if(!pq.empty())
		{
			ll t=pq.top();
			while(i<t&&(!pq.empty()))
			{
				pq.pop();
				sum-=dp[t];
				t=pq.top();
			}
			ans[a[i]]-=sum;
		}
		pq.push(l[i]);
		sum+=dp[l[i]];
	}
	for(ll i=1;i<=m;i++)cout<<ans[i]<<" ";
}
