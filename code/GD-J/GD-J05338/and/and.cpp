#include <bits/stdc++.h>
using namespace std;
long long a[200005];
bool cmp(int x,int y)
{
	return x > y;
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("ans.out","w",stdout);
	int n,m;
	cin >> n >> m;
	int mx = 0;
	for(int i = 1;i <= n;i++)
	{
		cin >> a[i];
	}
	sort(a + 1,a + n + 1,cmp);
	for(int i = 1;i <= n - m;i++)
	{
		int ca = a[i];
		for(int j = i + 1;j <= i + m - 1;j++)
		{
			ca = ca & a[j];
		}
		cout << endl;
		mx = max(mx,ca);
	}
	cout << mx;
	return 0;
}
