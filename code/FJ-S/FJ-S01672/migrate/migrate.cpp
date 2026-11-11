#include<iostream>
#include<cstdio>
#define ll long long
using namespace std;
const int N = 2e6+10;
ll c,t,n,d,a[N];
pair<ll,ll> check(ll step,ll u,ll v)
{
//	cout<<step<<":"<<u<<" "<<v<<endl; 
	if(u == v) return {step+1,-1};
	if(u > v) return {0,-1};
	ll cnt = 0,num = 0;
	for(int i = 1;i <= d;i++)
	{
		if(u+i > v) break;
		ll test = check(step+1,u+i,v).first;
		if(test == 0) break;
		if(test < num||num == 0)
		{
			cnt = 1;
			num = test;
		}
		else if(test == num) cnt++;
	}
	return {num,cnt};
}
void solve()
{
	cin>>n>>d;
	for(int i = 1;i <= n;i++)
		cin>>a[i];
	ll ans = 0;
	for(int i = 1;i <= n;i++)
		for(int j = i+1;j <= n;j++)
			if(check(1,i,j).second == 2) 
				ans++;
	cout<<ans<<endl;
}
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>c>>t;
//	check(0,1,5);
	while(t--) solve();
	return 0;
}
