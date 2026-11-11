#include <iostream>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <algorithm>
#include <cmath>
using namespace std;
int n;
long long m;
int cry[500005];
long long c[500005];
int ans = 1;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	for(int i = 0 ; i < n; i++)
	{
		cin >> cry[i];
	}
	sort(cry,cry+n);


	c[0] = 0;
	for(int i = 1 ; i < n; i++)
	{
		c[i] = c[i-1] + (long long)((long long)i * (long long)((long long)cry[i] - (long long)cry[i-1]));
		
	}
	for(int i = 0 ; i < n; i++)
	{
		int cnt = 0;
		int l = 0, r = i, mid;
		mid = l+(r-l)/2;
		while(l<=r)
		{
			mid = l+(r-l)/2;
			//cout << c[i] - c[mid] << ' ';
			if(c[i] - c[mid] - (mid)*(cry[i] -cry[mid])<= m)
			{
				cnt = mid;
				r = mid - 1;
			}else
			{
				l = mid + 1;
			}
		}
		//cout << '\n';
		ans = max(ans,i - cnt + 1);
	}
	cout << ans;
	return 0;
}
