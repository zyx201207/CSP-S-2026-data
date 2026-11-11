#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int n;
ll m, ans = 0;
ll a[500005];

bool cmp(ll a, ll b)
{
	return a > b;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	
	cin>>n>>m;
	
	int l = 0, r = n;
	int mid = (l + r) / 2;
	
	for(int i=1; i<=n; i++)
		cin>>a[i];
	sort(a+1, a+n+1, cmp);
	
	while(r > mid && mid > l)
	{
		ll cnt = 0;
		ll sum = 0;
		for(int j=r; j>=mid+1; j--)
		{
			sum += (a[mid] - a[j]);
			cnt++;
			if(sum > m)
				break;
		}
		if(sum > m)
		{
			l = mid;
			mid = l + (r-l) / 2;
		}
		if(sum <= m)
		{
			mid = l + (mid-l) / 2;
			ans = max(ans, cnt+1);
		}
	}
	if(ans == 0)
		cout<<"1"<<endl;
	else
		cout<<ans;
	return 0;
}
