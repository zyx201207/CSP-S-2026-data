#include<bits/stdc++.h>
using namespace std;
#define maxn 305
#define inf 0x3f3f3f3f
int c,t,n;
long long d;
long long x[maxn];
long long dis[maxn][maxn];
int num[maxn][maxn];
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin >> c >> t;
    while(t--){
        int ans = 0;
        cin >> n >> d;
        for(int i = 1;i <= n;i++){
            cin >> x[i];
            for(int j = 1;j <= n;j++){
                num[i][j] = 0;
                if(i == j) dis[i][j] = 0;
                else dis[i][j] = inf;
            }
        }
        for(int i = 1;i <= n;i++){
            for(int j = i - 1;j >= 1;j--){
                if(x[i] - x[j] <= d){
                    dis[i][j] = 1;
                    num[i][j] = 1;
                    continue;
                }
                break;
            }
            for(int j = i + 1;j <= n;j++){
                if(x[j] - x[i] <= d){
                    dis[i][j] = 1;
                    num[i][j] = 1;
                    continue;
                }
                break;
            }
        }
        for(int i = 1;i <= n;i++){
            for(int j = 1;j <= n;j++){
                for(int k = 1;k <= n;k++){
                    dis[i][j] = min(dis[i][j],dis[i][k] + dis[k][j]);
                }
            }
        }
        for(int i = 1;i <= n;i++){
            for(int j = i + 1;j <= n;j++){
                for(int k = i;k <= j;k++){
                    if(dis[k][j] != 1 || dis[i][k] + dis[k][j] != dis[i][j]) continue;
                    num[i][j] += num[i][k];
                }
            }
        }
        for(int i = 1;i <= n;i++){
            for(int j = 1;j <= n;j++){
                if(num[i][j] == 2){
                    ans++;
                }
            }
        }
        cout << ans << endl;
    }
    return 0;
}
