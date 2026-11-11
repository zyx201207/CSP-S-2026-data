#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
const ll N=1001;
ll c,n,m,d,q,w[N],k,a[501][N],t[501][N],x,y,f[N][N];
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> c >> n >> m >> d >> q;
	for(ll i=1;i<=m;i++)
		cin >> w[i];
	for(ll i=1;i<=m;i++)
		for(ll j=1;j<=m;j++)
			f[i][j]=0x3f3f3f3f;
	for(ll i=1;i<=n;i++)
	{
		cin >> k;
		for(ll j=1;j<=k;j++)
			cin >> a[i][j] >> t[i][j];
		for(ll j=1;j<=k;j++)
		{
			for(ll z=1;z<=k;z++)
			{
				if(z==j) continue;
				f[a[i][j]][a[i][z]]=min(f[a[i][j]][a[i][z]],t[i][j]+t[i][z]);
			}
		}
	}
	for(ll i=1;i<=m;i++)
	{
		for(ll j=1;j<=m;j++)
		{
			if(i==j) continue;
			for(ll z=1;z<=m;z++)
			{
				if(z==i||z==j) continue;
				f[i][j]=min(f[i][z]+f[z][j],f[i][j]);
			}
		}
	}
	while(q--)
	{
		cin >> x >> y;
		cout << f[x][y]+w[x]+w[y] << endl;
	}
	return 0;
}
