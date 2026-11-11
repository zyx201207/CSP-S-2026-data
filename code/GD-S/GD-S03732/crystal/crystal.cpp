#include<bits/stdc++.h>
using std::cin;
using std::cout;
using std::cerr;
using std::sort;
using std::max;
namespace my{
	int n;
	long long m,a[500005],sum[500005];
}using namespace my;

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	std::ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	for(int i = 1;i <= n;i += 1)
	{
		cin>>a[i];
	}
	sort(a + 1,a + 1 + n);
	for(int i = 1;i <= n;i += 1)
	{
		sum[i] = sum[i - 1] + a[i];
	}
	int ans = 1;
	for(int i = 2;i <= n;i += 1)
	{
		int l = 1,r = i;
		while(l < r)
		{
			int mid = (l + r) >> 1;
			if(a[i] * (i - mid) - sum[i - 1] + sum[mid - 1] <= m)
			{
				r = mid;
			}
			else
			{
				l = mid + 1;
			}
		}
		ans = max(ans,i - l + 1);
	}
	cout<<ans;
	return 0;
}
