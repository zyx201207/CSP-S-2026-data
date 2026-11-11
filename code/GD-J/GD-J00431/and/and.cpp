#include<iostream>
#include<cstdio>
using namespace std;
const int N = 2e5+5;
int a[N];
bool del[N];
int main()
{
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	int n, m, i, j, ans=0, cnt;
	cin >> n >> m;
	for(i = 1; i <= n; i++)
		cin >> a[i];
	for(j = 30; j >= 0; j--)
	{
		cnt = 0;
		for(i = 1; i <= n; i++)
		{
			if(del[i])
				continue;
			if(a[i] & (1 << j))
				cnt++;
		}
		if(cnt < m)
			continue;
		ans |= (1 << j);
		for(i = 1; i <= n; i++)
		{
			if(del[i])
				continue;
			if(!(a[i] & (1 << j)))
				del[i] = 1;
		}
	}
	cout << ans;
	return 0;
}
