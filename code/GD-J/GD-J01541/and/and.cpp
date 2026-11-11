#include <bits/stdc++.h>
using namespace std;
#define ll long long

const int N = 200005;
const int M = 35;
ll a[N];
bool d[N][M];//二进制 
bool pd[N];//判断这个数是否合法 
bool vis[N];
ll ans(0), maxx(-1);//最高位 
int temp(0);//ans二进制最高位 

void f(int o, ll x)
{
	ll jsq(0);
	while (x > 0)
	{
		jsq++;
		if (x & 1)
			d[o][jsq] = 1;
		else
			d[o][jsq] = 0;
		x >>= 1;
	}
	maxx = max(maxx, jsq);
	return;
}


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	
	int n, m;
	cin >> n >> m;
	
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
		pd[i] = true;
		f(i, a[i]);
	}
	
//	for (int i = 1; i <= n; i++)
//	{
//		for (int j = 1; j <= maxx; j++)
//		{
//			if (d[i][j])
//				cout << "1";
//			else
//				cout << "0";
//		}
//		cout << '\n';
//	}
	
	for (int i = maxx; i >= 1; i--)
	{
		int r = 0;
		for (int j = 1; j <= n; j++)
		{
			if (d[j][i])
				r++;
		}
		if (r >= m)
		{
			temp = i;
			break;
		}
	}
	
//	cout << temp << '\n';
		
	for (int i = temp; i >= 1; i--)
	{
		int sum(0);
		for (int j = 1; j <= n; j++)
		{
			if (d[j][i] && pd[j])
				sum++;
		}
		if (sum >= m)
		{
			for (int j = 1; j <= n; j++)
			{
				if (!d[j][i])
					pd[j] = false;
			}
			vis[i] = true;
		}
	}
	for (int i = 1; i <= temp; i++)
	{
		if (vis[i])
		{
			ans += pow(2, i - 1);
//			cout << i << ' ';
		}
			
	} 
	cout << ans;
	return 0;
} 


/*


4 2
3 15 12 12
 
5 3
31 3 1 15 7
*/

