#include<bits/stdc++.h>

using namespace std;
int a[300005];
int main()
{
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	bool flag = true;
	int ma = 0;
	int n, m;
	cin >> n >> m;
	for(int i = 1; i <= n; i++)
	{
		int tmp;
		cin >> tmp;
		a[tmp]++;
		if(tmp >= ma)
		ma = a[i];
		else
		flag = false;
	}
	if(flag)
	{
		int cnt = 0;
		int t = 1;
		while(t <= m)
		{
			cnt += a[t];
			cout << cnt << ' ';
			t++;
		}
	}
	return 0;
}
