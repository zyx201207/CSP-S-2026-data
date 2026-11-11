#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;
int a[N];
bool vis[N];

int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin >> n >> m;
	for(int i = 1;i <= n;i++) cin >> a[i];
	int ans = 0; 
	for(int i = 30;i >= 0;i--) 
	{
		int cnt = 0;
		for(int j = 1;j <= n;j++)
		{
			if(vis[j]) continue;
			if((a[j] >> i) & 1) cnt++;
		}
		if(cnt >= m)
		{
			ans += (1 << i);
			for(int j = 1;j <= n;j++)
			{
				if(vis[j]) continue;
				if(!((a[j] >> i) & 1)) vis[j] = 1;
			}
		}
	}
	cout << ans << endl;
	return 0;
}
