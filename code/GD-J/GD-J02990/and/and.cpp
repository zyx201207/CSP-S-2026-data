#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> PII;
const int N=2e5+10;
ll n,m;
ll a[N];
ll ans;
priority_queue<PII> q;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		ll b=a[i],s=0,l=0;
		while(b)
		{
			s+=(b&1?l:0);
			b>>=1;
			l++;
		}
		q.push({s,i});
	}
	ans=a[q.top().second];
	q.pop();
	for(int i=2;i<=m;i++)
	{
		if(!q.empty())
		{
			ans=ans&a[q.top().second];
			q.pop();
		}
	}
	cout<<ans;
	return 0;
}
