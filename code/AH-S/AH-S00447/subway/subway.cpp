#include "bits/stdc++.h"
#define int long long
using namespace std;
const int N = 5e5 + 10;
int C, n, m, d, q;
int w[N];
vector<int> a[N];
vector<int> t[N];
int kt[N];
int ans=0x3f3f3f3f3f3f3f3f;

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);

    cin >> C >> n >> m >> d >> q;
    for(int i=1; i<=m; i++) {
        cin >> w[i];
    }
    for(int i=1; i<=n; i++) {
        cin >> kt[i];
        for(int j=1; j<=kt[i]; j++) {
            int u,v;
            cin >> u >> v;
            a[i].push_back(u);
            t[i].push_back(v);
        }
    }
    while(q--) {
        int x,y;
        ans=0x3f3f3f3f3f3f3f3f;
        cin >> x >> y;
        int px1, py, qx, qy;
        qx = qy = ans;
        for(int i=1; i<=n; i++) {
            for(int j=0; j<kt[i]; j++) {
                if(a[i][j] == x) {
                    if(qx > t[i][j]) {
                        qx = t[i][j];
                        px1 = i;
                    }
                }
                if(a[i][j] == y) {
                    if(qy > t[i][j]) {
                        qy = t[i][j];
                        py = i;
                    }
                }
            }
        }
        cout << w[x] + w[y] + t[px1][x] + t[py][y] << '\n';
    }
	return 0;
}
