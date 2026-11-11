#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n;
	int m;
	cin >> n >> m;
	int a[n+1];
	for(int i = 1;i<=n;i++)
	{
		cin >> a[i];
	}
	sort(a+1,a+n+1);
	int ans = a[n];
	for(int i = n-1;i>=n-m+1;i--)
	{
		 ans = ans&a[i];
	}
	cout << ans;
	return 0;
}
//2 2 1
//a b c
//l   r
/*5 3
31 3 1 15 7*/
