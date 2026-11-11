#include<iostream>
#include<cstdio>
#include<algorithm>
#include<queue>
#define ll long long
using namespace std;
ll n,m,a[500010];
ll check(ll sta)
{
	priority_queue<ll> q;
	ll cost = 0,cnt = 0;
	for(ll i = 1;i <= n;i++)
	{
		if(a[i] > sta) break;
		cost+=(sta - a[i]);
		q.push(sta-a[i]);
		cnt++;
		while(cost > m)
		{
			cost -= q.top();
			cnt--;
			q.pop();
		}
	}
	return cnt;
}
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i = 1;i <= n;i++)
		cin>>a[i];
	sort(a+1,a+1+n);
	ll mid = 0,ans = 0;
	for(int i = 1;i <= n;i++)
		ans = max(ans,check(a[i]));
	cout<<ans;
	return 0;
}
