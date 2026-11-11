#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,x,y;
int w[500001];
vector<int> a[500],t[500];
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin >> c >> n >> m >> d >> q;
	bool hc[n][m];
	memset(hc,0,sizeof(hc));
	for(int i=1;i<=m;i++)
	{
		cin >> w[i];
	}
	for(int i=1;i<=n;i++)
	{
		int k,aa,tt;
		cin >> k;
		for(int j=1;j<=k;j++)
		{
			cin >> aa >> tt;
			a[i].push_back(aa);
			t[i].push_back(tt);
			hc[j][aa]=1;
		}
	}
	for(int i=1;i<=q;i++)
	{
		cin >> x >> y;
		for()
	}
	return 0;
}
