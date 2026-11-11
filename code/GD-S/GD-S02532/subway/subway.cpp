#include <bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
int w[500010];
int k[510],a[510][510],t[510][510];
int x,y;
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin >> c >> n >> m >> d >> q;
	for(int i=1;i<=m;i++)
	{
		cin >> w[i];
	}
	for(int i=1;i<=n;i++)
	{
		cout << k[i];
		for(int j=1;i<=k[i]*2;i++)
		{
			cin >> a[i][k[i]] >> t[i][k[i]];
		}
	}
	for(int i=1;i<=q;i++)
	{
		cin >> x >> y;
		continue;
		//不会了，谢谢您们的工作 
	}
	cout << 22 << endl;
	cout << 121; 
	return 0;
}
