#include <bits/stdc++.h>
#define int long long
using namespace std;
int n,m;
int sz[500005],qian[500005];
bool pd(int a)
{
	int sum,t1,t2;
	for (int i = 1;i <= n-a+1;i++)
	{
		sum = 0;
		for (int j = i;j <= i+a-2;j++)
		{
  			t1 = j-i+1;
			t2 = a-t1;
			if (t1 <= t2)
 				sum = (sz[j+1]-1)*(t1-t2)+(qian[i+a-1]-qian[j])-(qian[j]-qian[i-1]);
			else
				sum = sz[j]*(t1-t2)+(qian[i+a-1]-qian[j])-(qian[j]-qian[i-1]);
 			if (sum <= m)
 			{
// 				cout << i << ' ' << j << ' ' << sum << '\n';
				return 1;
			}
				
		}
		if ((sz[i+a-1]*(a-2)+sz[i+a-1]-qian[i+a-2]+qian[i-1]) <= m)
			return 1;
	}
	return 0;
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	for (int i = 1;i <= n;i++)
		cin >> sz[i];
	sort(sz+1,sz+n+1);
	for (int i = 1;i <= n;i++)
		qian[i] = qian[i-1]+sz[i]; 
	int l = 1,r = n+1,mid;
	while (l + 1 < r)
	{
		mid = l+(r-l)/2;
		if (pd(mid))
			l = mid;
		else
			r = mid;
	}
	cout << l;
	return 0;
} 
/*
5 8
-3 -1 2 2 7
*/
