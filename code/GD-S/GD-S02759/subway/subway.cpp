#include <iostream> 
using namespace std;
long long N = 100005;
int main(){
	long long c,n,m,d,q,ans = 0,w[N],a[N][N],t[N][N],x[N],y[N];
	cin >> c >> n >> m >> d >> q;
	for (int i = 1;i <= m;i++)
	{
		cin >> w[i];
	}
	for (int i = 1;i <= n;i++)
	{
		for (int j = 1;j <= n;j++)
		{
			cin >> a[i][j];
			cin >> t[i][j];
		}
	}
	for (int r = 1;r <= q;r++)
	{
		cin >> x[r];
		cin >> y[r];
	}
	for (int i = 1;i <= q;i++)
	{
		for (int j = 1;j <= q;j++)
		{
			ans = w[x[i]];
			for (int k = 1;k <= q;k++)
			{
				ans += t[j][k];
			}
		}
	}
	cout << ans;
}
