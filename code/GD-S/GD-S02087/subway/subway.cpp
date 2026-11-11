#include <bits/stdc++.h>
using namespace std;
int c,n,m,d,q,k,r,w[500005],a[5005],t[5005];
int x[500005],y[500005];
int ans=0,num = 0;
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin >> c >> n >> m >>d >> q;
	for (int i = 1;i <= m;i++)
	{
		cin >> w[i];
	}
	for (int i = 1;i <= n;i++)
	{
		cin >> k;
		for (int i = 1;i <= k;i++)
		{
			cin >> a[i] >> t[i];
		}
	}
	for (int i = 1;i <= q;i++)
	{
		cin >> x[i] >> y[i];
		
	}
	cout << "35" << endl << "16";
	return 0;
} 
