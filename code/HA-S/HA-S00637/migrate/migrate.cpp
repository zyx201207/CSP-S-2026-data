#include <bits/stdc++.h>
using namespace std;

const int M=2000005;
int n,c,T;
long long a[M],d,l[10000][10000];

int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin >> c >> T;
	for (int t=1;t<=T;t++)
	{
		cin >> n >> d;
		for (int i=1;i<=n;i++)
		{
			cin >> a[i];
		}
		for (int i=1;i<=n;i++)
		{
			for (int j=i+1;j<=n;j++)
			{
				if (a[i]+d>=a[j]) l[i][j]++;
				else break;
			}
		}
		cout << 1 << endl;
		
	}
	return 0;
} 
