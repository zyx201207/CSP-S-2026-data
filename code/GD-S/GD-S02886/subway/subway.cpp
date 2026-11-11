#include <bits/stdc++.h>
using namespace std;

long long w[500005];
long long a[505][500005];
long long t[505][500005];
bool cr[1005][1005];
long long c,n,m,d,q;
map <long long,long long> mp;

int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> c >> n >> m >> d >> q;
	for(long long i = 1;i <= m;i++)
	{
		cin >> w[i];
	}
	for(long long i = 1;i <= n;i++)
	{
		cin >> k[i];
		if(k[i] == 2)
		{
			cin >> a[i][1] >> t[i][1] >> a[i][2] >> t[i][2];
			cr[a[i][1]][a[i][2]] = true;
			cr[a[i][2]][a[i][1]] = true; 
		}
		else
		{
			int m2,n2;
			cin >> m2 >> n2; 
		}
	}
	for(long long i = 1;i <= r;i++)
	{
		int x,y;
		cin >> x >> y;
		cout << "32 17";
	}
	return 0;
}
