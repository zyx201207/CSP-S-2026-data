#include <bits/stdc++.h>
using namespace std;

const int N = 2 * 1e5 + 100;
int n, m, a[N], ans, ky, num[20];
bool p[N][20], p1[N];

int main()
{
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	for(int i = 1; i <= n; i ++)
	{
		cin >> a[i];
		long long md = a[i], cur = -1;
		while(md != 0)
		{
			++cur;
			if(md % 2 == 1)
			{
				num[cur] ++;
				p[i][cur] = true;
			} 
			md /= 2;
		}
	}
	for(int i = 20; i >= 0; i --)
	{
		if(num[i] >= m)
		{
			ans += 1 << i;
			for(int j = 1; j <= n; j ++)
			{
				if(p[j][i] == false && p1[j] == false)
				{
					p1[j] = true;
					for(int k = i - 1; k >= 0; k --)
					{
						if(p[j][k] == true)
						{
							num[k] --;
						}
					}
				}
			}
		}	
	}
	cout << ans << "\n";
}
