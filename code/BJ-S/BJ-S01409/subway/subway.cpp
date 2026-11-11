#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
typedef long long i64;
constexpr int ms1 = 505;
constexpr int ms2 = 5e5 + 5;
using namespace std;

int c,n,m,d,q,ki,x,y;
i64 g[ms1][ms1];
i64 w[ms2];

struct node{
    int ai;
    i64 ti;
}a[ms1];

int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    memset(g,0x3f,sizeof g);

    cin >> c >> n >> m >> d >> q;

    for(int i = 1;i <= m;i++)
    {
        cin >> w[i];
    }
    for(int i = 1;i <= n;i++){
        cin >> ki;
        for(int i = 1;i <= ki;i++){
            cin >> a[i].ai >> a[i].ti;
        }
        for(int i = 1;i <= ki;i++){
            for(int j = 1;j <= ki;j++){
                if(i == j) continue;
                g[a[i].ai][a[j].ai] = min(g[a[i].ai][a[j].ai],a[i].ti + a[j].ti);
            }
        }
    }

    for(int i = 1;i <= m;i++){
        g[i][i] = 0;
    }

    for(int k = 1;k <= m;k++){
        for(int i = 1;i <= m;i++){
            for(int j = 1;j <= m;j++){
                if(i == k || j == k || i == j) continue;
                g[i][j] = min(g[i][j],g[i][k] + g[k][j]);
            }
        }
    }


    while(q--){
        cin >> x >> y;
        cout << g[x][y] + w[x] + w[y] << "\n";
    }
    return 0;
}
