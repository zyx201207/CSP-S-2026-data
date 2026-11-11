#include <bits/stdc++.h>
using namespace std;
int n,m,a[200005],maxn,num;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	for(int i = 1;i <= n;i++)
	{
		cin >> a[i];
	}
	num = a[1];
	sort(a + 1,a + n + 1);
	if(m == 1)
	{
		cout << a[n];
	}
	else if(m == n)
	{
		for(int i = 2;i <= n;i++)
		{
			num &= a[i];
		}
		cout << num;
	}
	else
	{
		num = a[n];
		for(int i = n - 1;i >= n - m + 1;i--)
		{
		    num &= a[i];		
		}
		cout << num;
	}
	return 0;
} 
