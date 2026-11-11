#include <bits/stdc++.h>
using namespace std;
long long c,n,m,d,q;
long long w[500005],x[500005],y[500005],t[500005][500005];
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> c >> n >> m >> d >> q;
	for(int i=1;i<=m;i++) cin >> w[i];
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=2*t[1][1]+1;j++)
		{
			cin >> t[i][j];
		}
    } 
    for(int i=1;i<=q;i++)
    {
    	cin >> x[i] >> y[i];
	}
	
	return 0;
}
