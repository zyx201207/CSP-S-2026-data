#include<bits/stdc++.h>
using namespace std;
const int N = 5e5 + 10;
const int inf = 1e9;
int c,n,m,d,q;
int w[N];
int k[N];
int a[N][N],t[N][N];

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
    while(q--){
        int x,y;
        cin >> x >> y;
        long long sum = 0;
        sum += w[x] + w[y];
        int mnx = inf,mny = inf;
        for(int i = 1;i <= n;i++){
            for(int j = 1;j <= k[i];j++){
                if(a[i][j] == x) mnx = min(mnx,t[i][j]);
                else if(a[i][j] == y) mny = min(mny,t[i][j]);
            }
        }
        sum += mnx + mny;
        int sx = 0,sy = 0;
        for(int i = 1;i <= n;i++){
            for(int j = 1;j <= k[i];j++){
                if(a[i][j] == x){
                    if(t[i][j] == mnx) sx = i;
                }else if(a[i][j] == y){
                    if(t[i][j] == mny) sy = i;
                }
            }
        }
        if(sx == sy){
            cout << sum << endl;
            continue;
        }
        bool flag = false;
        for(int i = 1;i <= k[sx];i++){
            for(int j = 1;j <= k[sy];j++){
                if(a[sx][i] == a[sy][j]){
                    sum += t[sx][i] + t[sy][j];
                    cout << sum << endl;
                    flag = true;
                    break;
                }
                if(flag == true) break;
            }
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
