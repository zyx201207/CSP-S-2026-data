#include <iostream>
#include <algorithm>
using namespace std;
int w[500005],a[505][500005],k[505],t[505][500005];
bool vis[505][500005];
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q;
	cin >> c >> n >> m >> d >> q;
	for(int i = 1; i <= m; i++){
		cin >> w[i];
	}
	for(int i = 1; i <= n; i++){
		int k;
		cin >> k;
		for(int j = 1; j <= k; j++){
			cin >> a[i][j] >> t[i][j];
		}
	}
	while(q--){
		int x,y;
		cin >> x >> y;
		int s = 0;
		s += (w[x]+w[y]);
		int h = 0,e = 0,minn = 0;
		for(int i = 1; i <= n; i++){
			for(int j = i; j <= m; j++){
				if(a[i][j] == x) h = i;
				if(a[i][j] == y) e = i;
				if(vis[a[i][j]]){
					if(t[i][j] < minn){
						minn = t[i][j];
					}
				}
			}
		}
		if(h == e){
			cout << s << endl;
			continue;
		}
		else cout << s + minn << endl;
	}
	return 0;
}
