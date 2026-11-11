#include <bits/stdc++.h>
#define int long long
using namespace std;
int n;
int a[200005];
char c[200005];
signed main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	for(int i = 1;i <= n;i++)
	{
		cin >> a[i] >> c[i];
	}
	int pos1 = 1,pos2 = 1;
	int pos3 = n,pos4 = a[n];
	int ans = 0;
	while(true)
	{
		int now = min(a[pos1]-pos2+1,pos4);
		if(c[pos1] != c[pos3])
		{
			ans += now;
		}
		pos2 += now;
		pos4 -= now;
		if(pos2 > a[pos1])
		{
			pos1++;
			pos2 = 1;
		}
		if(pos4 == 0)
		{
			pos3--;
			pos4 = a[pos3];
		}
		if(pos1 > n || pos3 < 0)break;
	}
	cout << ans/2;
	return 0;
}

