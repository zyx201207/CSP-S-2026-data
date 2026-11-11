#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
int w[500005];
int a[505][500005],t[505][500005],k[505];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin >> c >> n >> m >> d >> q;
	for(int i = 1;i <= m;i++){
		cin >> w[i];
	}
	for(int i = 1;i <= n;i++){
		cin >> k[i];
		for(int j = 1;j <= k[i];j++){
			cin >> a[i][j] >> t[i][j];
		} 
	}
	for(int test = 1;test <= q;test++){
		int x,y;
		cin >> x >> y;
		int ans = 1e9;
		for(int i = 1;i <= n;i++){
			for(int j = 1;j <= k[i];j ++){
				ans = min(ans,a[i][j] + t[i][j]);
			}
		}
		cout << ans << endl;
	}
}
