#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define sc cout
#define ull unsigned long long
ll sz[500010];
ll cf[500010];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	ll n,m;
	ll maxn=0;
	ll cnt=0,jsq=0;
	cin>>n>>m;
	for(ll i=1;i<=n;i++)
	{
		cin>>sz[i];
	}
	sort(sz+1,sz+n+1);
	for(ll i=1;i<n;i++)
	{
		cf[i]=sz[i+1]-sz[i];
	}
	for(ll i=n,j=n-1;i>=0,j>=0;)
	{
		if(cnt>m)
		{
			maxn=max(maxn,i-j-1);
			cnt-=(i-j-1)*cf[i-1];
			jsq-=cf[i-1];
			i--;
		}
		else if(cnt==m)
		{
			maxn=max(maxn,i-j);
			cnt-=(i-j)*cf[i-1];
			jsq-=cf[i-1];
			i--;
		}
		else 
		{
			cnt+=cf[j]+jsq;
			jsq+=cf[j];
			j--;
		}
	}
	cout<<maxn;
	return 0;
}
