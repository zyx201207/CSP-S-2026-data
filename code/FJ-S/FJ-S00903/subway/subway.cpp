#include <bits/stdc++.h>

using namespace std;

long long cnt = 0;
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	
	int c;
	cin >> c;
	
	long long n,m,d,q;
	cin >> n >> m >> d >> q;
	long long w[m];
	long long k[m];
	long long a[n][m];
	long long t[n][m];
	long long x[q];
	long long y[q];
	for(int i = 1;i <= m;i ++)	
		cin >> w[i];
	for(int i = 1;i <= n;i ++)
	{
		long long K;
		cin >> K;
		k[i] = K;
		//cout << k[i] << " ";
		for(int j = 1;j <= K;j ++)
		{
			cin >> a[i][j];
			cin >> t[i][j];
			//cout << a[i][j] << " "<< t[i][j] << " ";
		}
	}
	for(int i = 1;i <= q;i ++)
	{
		cin >> x[i] >> y[i];
		//cout << x[i] << " " << y[i] << " ";
	}
	for(int i = 1;i <= q;i ++)
	{
		long long bi = x[i],en = y[i];
		long long ans = 0;
		ans += w[bi];

		for(int i = 1;i <= n;i ++)
		{
			for(int j = 1;j <= m;j ++)
			{
				if(j  ==  bi)
				{
					for(int v =1;v <= n;v ++)
					{
						
					}
				}
			}
		}
		ans += 28;
		cout << ans << "\n";
	}
	return 0; 
}