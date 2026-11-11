#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAXN = 5e5+10;

ll n, m;
ll a[MAXN];

bool check(int k)
{
	ll cur = 0;
	for(int i=1;i<k;i++) cur += a[i];
	for(int i=k;i<=n;i++)
	{
		if(cur + m >= a[i] * (k-1)) return true;
		cur -= a[i-k+1];
		cur += a[i];
	}
	return false;
}

int main()
{
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1, a+n+1);
	int l = 1, r = n;
	int ans = l;
	while(l <= r)
	{
		int mid = l+r>>1;
		if(check(mid)) l = mid+1, ans = mid;
		else r = mid-1;
	}
	cout<<ans;
	return 0;
}
