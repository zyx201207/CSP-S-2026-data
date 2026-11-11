#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N=5e5+10;
ll n,m,ans,a[N];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	queue<ll> q;
	ll t=0;
	for(int i=n;i>=1;i--)
	{
		while(!q.empty()&&t+q.front()-a[i]>m)
		{
			ans=max(ans,(ll)q.size());
			ll v=q.front();
			q.pop();
			ll d=v-q.front();
			ll p=q.size();
			t-=d*p;
		}
		if(!q.empty()) t+=q.front()-a[i];
		q.push(a[i]);
	}
	ans=max(ans,(ll)q.size());
	cout<<ans;
	return 0;
}
