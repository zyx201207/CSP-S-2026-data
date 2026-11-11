#include <iostream>
using namespace std;
const int MAXN = 2000005;
int C,T,n,suf[MAXN],pre[MAXN];
long long D,X[MAXN],f[MAXN][3];
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> C >> T;
    while(T--){
        cin >> n >> D;
        for(int i = 1;i <= n;i++){
            cin >> X[i];
        }
        int ptr = 1;
        for(int i = 1;i <= n;i++){
            while(ptr <= n && X[ptr] <= X[i] + D){
                ptr++;
            }
            suf[i] = ptr - 1;
        }
        ptr = n;
        for(int i = n;i;i--){
            while(ptr && X[ptr] >= X[i] - D){
                ptr--;
            }
            pre[i] = ptr + 1;
        }
        for(int i = 1;i <= n;i++){
            f[i][0] = f[i][1] = f[i][2] = 0;
        }
        for(int i = 1;i <= n;i++){
            if(suf[i] > i){
                f[suf[i]][0]++;
            }
            if(suf[i] - 1 > i){
                f[suf[i]][2]++;
            }
        }
        for(int i = 1;i <= n;i++){
            if(suf[i] > i && pre[suf[i]] == i){
                f[suf[i]][0] += f[i][0];
                f[suf[i]][1] += f[i][1];
            }
            if(suf[i] - 1 > i && pre[suf[i] - 1] == i){
                f[suf[i]][2] += f[i][0];
            }
            if(suf[i] > i && pre[suf[i]] == i - 1){
                f[suf[i]][1] += f[i][2];
            }
        }
        long long ans = 0;
        for(int i = 1;i <= n;i++){
            if(pre[i] < i){
                ans += f[pre[i]][1];
            }
            if(pre[i] + 1 < i){
                ans += f[pre[i] + 1][2];
            }
        }
        cout << ans << '\n';
    }
    return 0;
}
