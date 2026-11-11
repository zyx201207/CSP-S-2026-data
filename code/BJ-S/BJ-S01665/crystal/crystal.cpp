#include<bits/stdc++.h>
using namespace std;

#define ll long long
const int N = 5e5+10;

ll a[N],n,m,sum[N],d[N],sumd[N];
bool v[N];

bool check(int x)
{
	bool f = 0;
	for(int i = 1; i<= n-x+1; i++)
	{
		int j = i+x-1;
		if(sum[j]-d[j]*(i-1)+sumd[i] <= m) 
		{
			f = 1;
		}
	}
	return v[x] = f;
}

int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(int i = 1; i<= n; i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i = 1; i<= n; i++)
	{
		if(i == 1) v[i] = 1, sum[i] = 0, d[i] = 0,sumd[i] = 0;
		else
		{
			d[i] = d[i-1]+a[i]-a[i-1];
			sum[i] = sum[i-1]+(d[i]-d[i-1])*(i-1);
			if(sum[i] <= m) v[i] = 1;
			sumd[i] = sumd[i-1]+d[i];
		}
	}
	ll l = 1, r = n, ans = 0;
	while(l < r)
	{
		int mid = (l+r+1)/2;
		if(v[mid] || check(mid))
		{
			ans = mid;
			l = mid;
		}
		else
		{
			r = mid-1;
		}
	}
	cout<<ans;
	return 0;
}
