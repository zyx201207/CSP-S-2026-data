#include "bits/stdc++.h"
using namespace std;
int C;
int T;
int n, d;
int x[200006];
vector<int> g[65000];
int ans, minn=0x3f3f3f3f;
int cnt=0;

void dfs(int x,int y, int p) {
    if(x == y) {
        if(minn > p) {
            minn = p;
            ans=1;
        }else if(minn == p) {
            ans++;
        }
        return ;
    }
    int len = g[x].size();
    for(int i=0; i<len; i++) {
        dfs(g[x][i],y, p+1);
    }
}

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);

    cin >> C >> T;
    g[1].push_back(1);
    while(T--) {
        cnt = 0;
        cin >> n >> d;
        if(n<=5000) {
            for(int i=1; i<=n; i++) {
                cin >> x[i];
            }
            for(int i=1; i<=n; i++) {
                g[i].clear();
                for(int j=i+1; j<=n; j++) {
                    if(x[j] - x[i] <= d) {
                        g[i].push_back(j);
                    }else break;
                }
            }
            for(int i=1; i<=n; i++) {
                for(int j=i+1; j<=n; j++) {
                    minn = 0x3f3f3f3f;
                    ans = 0;
                    dfs(i,j,0);
                    if(ans==2) {
                        cnt++;
                    }
                }
            }
            cout << cnt<< '\n';
        } else {
            bool flag = false;
            for(int i=1; i<=n; i++) {
                cin >> x[i];
                if(i<3) continue;
                if(x[i]-x[i-1] != x[i-1]-x[i-2]) flag = true;
            }
            if(!flag) {
                cout << 0 <<endl;
            }else{
                cout << 1 << endl;
            }
        }

    }
	return 0;
}
