#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll w[1001];
ll f[1001][1001];
ll llMax = 1LL<<61;
int main(){
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    int c,n,m,d,q;
    cin >> c >> n >> m >> d >> q;
    for(int i = 0 ; i < m ; i ++){
        cin >> w[i];
    }
    if(c >= 7 && c <= 11){
        int maxP = n + 1;
        for(int i = 0 ; i < maxP ; i ++){
            for(int j = 0 ; j < maxP ; j ++){
                if(i == j){
                    f[i][j] = 0;
                }else{
                    f[i][j] = llMax;
                }
            }
        }
        for(int i = 0 ; i < n ; i ++){
            int k;
            cin >> k; // k = 2
            int a1, a2, t1, t2;
            cin >> a1 >> t1 >> a2 >> t2;
            a1 -= 1;
            a2 -= 1;
            f[a1][a2] = t1 + t2;
            f[a2][a1] = t1 + t2;
        }
        // floyd
        for(int r = 0 ; r < maxP ; r ++){
            for(int x = 0 ; x < maxP ; x ++){
                if(x == r) continue;
                for(int y = 0 ; y < maxP ; y ++){
                    if(y == r) continue;
                    f[x][y] = min(f[x][y], f[r][y] + f[x][r]);
                }
            }
        }

    }else{
        int eIndex = m + 1;
        int maxP = n + m + 1;
        for(int i = 0 ; i < maxP ; i ++){
            for(int j = 0 ; j < maxP ; j ++){
                if(i == j){
                    f[i][j] = 0;
                }else{
                    f[i][j] = llMax;
                }
            }
        }
        for(int i = 0 ; i < n ; i ++){
            int k;
            cin >> k;
            int vi2 = eIndex + i;
            for(int j = 0 ; j < k ; j ++){
                int a;
                ll t;
                cin >> a >> t;
                a -= 1;
                f[vi2][a] = t;
                f[a][vi2] = t;
            }
        }
        // floyd
        for(int r = 0 ; r < maxP ; r ++){
            for(int x = 0 ; x < maxP ; x ++){
                if(x == r) continue;
                for(int y = 0 ; y < maxP ; y ++){
                    if(y == r) continue;
                    f[x][y] = min(f[x][y], f[r][y] + f[x][r]);
                }
            }
        }
    }
    // query
    for(int i = 0 ; i < q ; i ++){
        int x,y;
        cin >> x >> y;
        x -= 1;
        y -= 1;
        cout << (f[x][y] + w[x] + w[y]) << endl;
    }
	return 0;
}
