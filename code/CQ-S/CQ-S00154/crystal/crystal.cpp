#include <iostream>
#include <algorithm>
using namespace std;
#define int long long
int a[100010],c[100010];
signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m,maxn = 0;
	bool flag = 1;
	cin >> n >> m;
	for(int i = 1 ; i <= n ; i ++)
	{
		cin >> a[i];
		c[i] = a[i] - a[i - 1];
	}
	for(int i = 3 ; i <= n ; i ++)
	{
		if(c[i] != c[i - 1])
		{
			flag = 0;
		}
	}
	if(flag == 1)
	{
		int s = 0,i = 0;
		while(s <= m)
		{
			i ++;
			s += (c[2] * i);
		}
		cout << i << endl;
		return 0;
	}
	sort(a + 1,a + n + 1);
	for(int i = 1 ; i <= n ; i ++)
	{
		int t = m,j = i - 1,cnt = 1;
		while(t >= (a[i] - a[j]) && j >= 1)
		{
			cnt ++;
			t -= (a[i] - a[j]);
			j --;
		}
		maxn = max(maxn,cnt);
	}
	cout << maxn << endl;
	return 0;
}
