#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    int c,n,m,d,p;
    cin >> c >> n >> m >> d >> p;
    int a[500] = {},t[509][509] = {};
    for(int i = 1;i <= 509;i++){
        for(int j = 1;j <= 509;j++){
            t[i][j] = 0x3f;
		}
    }
    for(int i = 1;i <= m;i++){
        cin >> a[i];
    }
    for(int i = 1;i <= n;i++){
        int k,b[509] = {},q[509] = {};
        cin >> k;
        for(int j = 1;j <= k;j++){
            cin >> b[i] >> q[i]; 
        } 
        for(int i = 1;i <= k;i++){
            for(int j = i;j <= k;j++){
                t[b[i]][b[j]] = min(t[b[i]][b[j]],q[i] + q[j]);
            }
        }
    }
    for(int i = 1;i <= n;i++){
        for(int j = 1;j <= n;j++){
            for(int k1 = 1;k1 <= n;k1++){
                t[i][j] = min(t[i][j],t[i][k1] + t[k1][j]);
            }
        }
    }
    for(int i = 1;i <= p;i++){
        int x,y;
        cin >> x >> y;
        cout << t[x][y] + a[x] + a[y] << endl;
    }
    return 0;
}
