#include<bits/stdc++.h>
using namespace std;

int n;
long long m;
long long a[500010];

bool check(int mid)
{
	long long sum = 0;
	for(int i = 1; i <= mid; i++)
	{
		sum += a[mid]-a[i];
	}
	if(sum <= m) return true;
	for(int i = mid+1; i <= n; i++)
	{
		sum -= a[i-1]-a[i-mid];
		sum += (long long)(mid-1)*(a[i] - a[i-1]);
		if(sum <= m) return true;
	}
	return false;
}

int main() 
{
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
	sort(a+1, a+n+1);
	int l = 1, r = n;
	while(l < r)
	{
		int mid = (l+r+1)/2;
		if(check(mid))
		{
			l = mid;
			//cout << l << " ";
		}else
		{
			r = mid-1;
		}
	}
	cout << l;
	return 0;
}
