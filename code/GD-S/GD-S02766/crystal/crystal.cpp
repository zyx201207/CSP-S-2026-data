#include<bits/stdc++.h>
using namespace std;
int n;
long long m;
vector<long long> a;
vector<long long> h;
long long ans = 0;
long long find(int i)
{
	int N = n;
	long long begin = 1,end = i-1;
	while(N>>1)
	{
		long long mid = (begin + end + 1)/2;
		if(mid == 1) return i;
		long long x = a[i-1]*(i-mid);
		long long y = h[i-1] - h[mid-1];
		long long p = a[i-1]*(i-mid+1);
		long long q = h[i-1] - h[mid-2];
		if(x - y <= m && p - q > m)
		{
			return i-mid+1;
		}
		else if(x - y <= m)
		{
			end = mid - 1;
		}
		else
		{
			begin = mid;
		}
	}
	return 0;
} 
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	a.resize(n);
	h.resize(n+1,0);
	for(int i = 0;i < n;i++)
	{
		cin >> a[i];
	}
	sort(a.begin(),a.end());
	for(int i = 1;i <= n;i++)
	{
		h[i] = h[i-1]+a[i-1];
		ans = max(ans,find(i));
	}
	cout << ans;
	return 0;
}
