#include<bits/stdc++.h>
using namespace std;
using ll=long long;

const ll N=5e5+10;
ll n,m,num,ans,cnt,a[N];
priority_queue<ll,vector<ll>,greater<ll>> q;

void solve()
{
	cin>>n>>m;
	for(ll i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	
	for(ll i=1;i<=n;i++)
	{
		num+=(a[i]-a[i-1])*q.size();
		cnt++;
		while(num>m)
		{
			num-=(a[i]-q.top());
			q.pop();
			cnt--;
		}
		ans=max(ans,cnt);
		q.push(a[i]);
	}
	cout<<ans;
	
	return;
}

int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	solve();
	return 0;
} 
