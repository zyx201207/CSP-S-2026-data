#include<bits/stdc++.h>
using namespace std;

int c,n,m,d,q,w[1005];
int a[1005][1005],z[1005],t[1005];
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	memset(a,0x3f,sizeof(a));
	cin >> c >> n >> m >> d >> q;
	for(int i=1;i<=m;i++) cin >> w[i];
	for(int i=1;i<=n;i++){
		int k;
		cin >> k;
		memset(z,0,sizeof(z));
		memset(t,0,sizeof(t));
		for(int i=1;i<=k;i++){
			cin >> z[i] >> t[i];
		}
		for(int i=1;i<=k;i++){
			for(int j=i+1;j<=k;j++){
				a[z[i]][z[j]] = min(a[z[i]][z[j]],t[i]+t[j]);
			}
		}
	}
	for(int i=1;i<=m;i++) a[i][i] = 0;
	for(int k=1;k<=m;k++){
		for(int i=1;i<=m;i++){
			for(int j=1;j<=m;j++){
				a[i][j] = min(a[i][j],a[i][k]+a[k][j]);
			}
		}
	}
	for(int i=1;i<=q;i++){
		int x,y;
		cin >> x >> y;
		cout << a[x][y] + w[x] + w[y] << endl;
	}
	return 0;
} 
