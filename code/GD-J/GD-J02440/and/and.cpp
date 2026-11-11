#include <bits/stdc++.h>
using namespace std;
int n, m, sum[35], a[200005], ans;
bool b[200005];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout); 
	cin >> n >> m;
	//cout << n << ' ' << m << endl;
	for (int i=1; i<=n; i++)
	{
		//cout << i << ' ';
		cin >> a[i];
		//cout << a[i] << ' ';
		//assert(0);
		b[i]=1;
		for (int j=0; j<=29; j++)
		{
			if (a[i]&(1<<j))
			{
				sum[j]++;
			}
		}
	}
	for (int i=29; i>=0; i--)
	{
		//cout << i << endl;
		if (sum[i]>=m)
		{
			ans+=(1<<i);
			//cout << ans << endl;
			for (int j=1; j<=n; j++)
			{
				if (b[j]==0)
				{
					continue;
				}
				if ((a[j]&(1<<i))==0)
				{
					b[j]=0;
					for (int k=0; k<=29; k++)
					{
						if ((a[j]&(1<<k)))
						{
							sum[k]--;
							/*cout << a[j] << ' ' << k << endl;
							cout << (3&(1<<1)) << endl;*/
						}
						//cout << k << '\n';
					}
					/*for (int k=0; k<=29; k++)
					{
						cout << sum[k] << ' ';
						//cout << k << '\n';
					}
					cout << '\n';*/
				}
			}
		}
	}
	//assert(0);
	cout << ans << endl;
	return 0;
}
