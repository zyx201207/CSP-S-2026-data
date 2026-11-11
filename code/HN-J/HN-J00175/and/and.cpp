#include <bits/stdc++.h>
#define int long long
#define endl '\n';
using namespace std;
const int N = 2e5+10;
int n,m,a[N],w,t,qq,zz,gg,k;
bool hh(int x)
{
	while(x > 1)
	{
		int aaa = x/2;
		x -= aaa;
		if (x%2 == 1 && x != 1)
		{
			return false;
		}
//		cout << x << " ";
	}
	return true;
}
void dfs(int x,int fa,int fr)
{
	if (fa > m) return ;
	if (x >= n)
	{
		if (fa == m)
		{
			k = max(k,fr);
		}
		return ;
	}
	dfs(x+1,fa,fr);
	int aaa = fr&a[x+1];
	dfs(x+1,fa+1,aaa);
}
signed main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout); 
	cin >> n >> m >> a[1];
	w = a[1];
	for (int i = 2;i <= n;i++)
	{
		cin >> a[i];
		int yq = a[i]+1;
		if (hh(yq) == true)
		{
			zz++;
		}
		if (a[i] == i-1)
		{
			qq++;
			w = w&a[i];
		}
	}
	if (a[1] == 0 && qq == n-1)
	{
		cout << 0;
		return 0;
	}
	int yq = a[1]+1;
	if (hh(yq) == true && zz == n-1)
	{
		sort(a+1,a+n+1);
		cout << a[n-2];
		return 0;
	} 
	for (int i = 1;i < n;i++)
	{
		dfs(i,1,a[i]);
	}
	cout << k;
	return 0;
}
