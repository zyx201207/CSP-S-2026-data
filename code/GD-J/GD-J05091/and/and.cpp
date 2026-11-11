#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
int n,m,a[N],ans;
bool f(int n)
{
	if(n == 1) return true;
	if(n % 2 == 1) return false;
	return f(n / 2);
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	for(int i = 1;i <= n;i++)
	{
		cin >> a[i];
	}
	sort(a + 1,a + n + 1,greater<int>());
	for(int i = 1;i <= n;i++)
	{
		if(f(a[i] + 1) && ans < m - 1)
		{
			ans++;
			a[i] = 0;
		}
	}
	int mx = 0;
	for(int i = 1;i <= n;i++)
	{
		mx = max(mx,a[i]);
	}
	cout << mx;
	return 0;
} 

