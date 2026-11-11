#include<bits/stdc++.h>
using namespace std;
int c , n , m , d , q ,a , w[500010] , t[501][501];
bool fa[500010][501];
int ans = INT_MAX;
struct subway{
    int k , t[500010];
}sub[501];
void solve(int x1 , int y1){
    for(int i = 1;i <= n;i++){
        if(fa[x1][i]){
            for(int j = 1;j <= n;j++){
                if(fa[y1][j]){
                    ans = min(ans,t[i][j]);
                }
            }
        }
    }
    return;
}
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);

    cin >> c >> n >> m >> d >> q;
    for(int i = 1;i <= n;i++){
        for(int j = 1;j <= n;j++)t[i][j] = INT_MAX;
    }
    for(int i = 1;i <= m;i++)cin >> w[i];
    for(int i = 1;i <= n;i++){
        cin >> sub[i].k;
        for(int j = 1;j <= sub[i].k;j++){
                cin >> a >> sub[i].t[j];
                fa[a][i] = 1;
        }
    }
    for(int i = 1;i <= m;i++){
        for(int j = 1;j <= n;j++){
            if(fa[i][j]){
             for(int k = 1;k <= n;k++){
                  if(j != k && fa[i][k]){
                        if(t[j][k] > sub[j].t[i] + sub[k].t[i])t[j][k] = sub[j].t[i] + sub[k].t[i];
                   }
               }
            }
        }
    }
    for(int i = 1;i <= n;i++){
        for(int j = 1;j <= n;j++){
            for(int k = 1;k <= n;k++){
                t[i][j] = min(t[i][j],(t[i][k]+t[k][j]));
            }
        }
    }
 
    int x , y;
    for(int i = 1;i <= q;i++){
        cin >> x >> y;
        solve(x,y);
        cout << ans << '\n';
        ans = 0;
   }
    return 0;
}
