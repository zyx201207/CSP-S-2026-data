#include <bits/stdc++.h>
using namespace std;
#define ll long long 
const ll N = 5e5 + 7;
const ll INF= LONG_MAX;
ll n,m;
ll a[N];
ll pre[N];
ll ans;

bool check(int x)
{
	for(int i = x;i<=n;i++)
	{
		ll tmp = x*a[i]-pre[i] + pre[i-x+1];
		if(tmp <= m)
		{
			return true;
		}
	}
	return false;
}
int main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)
	{
		pre[i] = pre[i-1]+a[i];
//		cout<<pre[i]<<" ";
	}
//	cout<<endl<<endl;
	int l = 1,r = n;
	while(l < r)
	{
//		cout<<l<<" "<<r<<endl;
		int mid = (l + r + 1) / 2;
		if(check(mid))
		{
			l = mid;
		}
		else
		{
			r = mid - 1;
		}
	}
	
	cout<<l<<endl;
	return 0;
}
/*
5 5
1 2 4 8 9

5 8
-3 -1 2 2 7
*/
