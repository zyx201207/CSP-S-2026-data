#include <bits/stdc++.h>
using namespace std;

int n,m,cnt;
long long a[200005],mi[35],ans = 2147483647;

bool cmp(int x,int y)
{
	return x > y;
}

int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	mi[0] = 1;
	for(int i = 1;i <= 31;i++)	mi[i] = mi[i - 1] * 2;
	cin >> n >> m;
	for(int i = 1;i <= n;i++)	cin >> a[i];
	for(int p = 30;p >= 1;p--)
	{
		sort(a + 1,a + n + 1,cmp);
		cnt = 0;
		for(int i = 1;i <= n;i++)
		{
			if(a[i] >= mi[p])	cnt++;
			else	break;
		}
		if(cnt >= m)	break;
		for(int i = 1;i <= cnt;i++)	a[i] -= mi[p];
	}
	for(int i = 1;i <= m;i++)	ans &= a[i];
	cout << ans << endl;
	return 0;
}
