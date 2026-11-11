#include <bits/stdc++.h>
using namespace std;
long long len[5005];
int f[5005][5005];
long long n,d;
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int c,T;
    scanf("%d%d",&c,&T);
    for(int ux = 1;ux <= T;ux++){
        cin >> n >> d;
        for(int i = 1;i <= n;i++){
            cin >> len[i];
        }
        for(int i = 1;i <= n;i++){
            int j = i + 1;
            for(;j <= n && abs(len[j] - len[i]) <= d;j++){
                f[i][j] = 1;
            }
            for(;j <= n;j++){
                if(j == i + 2){
                    if(abs(len[i + 1] - len[i]) <= d && abs(len[j] - len[i]) <= d){
                        f[i][j] = 1;
                    }
                }
                else if(j == i + 3){
                    if((abs(len[i + 1] - len[i]) <= d && abs(len[j] - len[i + 1]) <= d)){
                        if((abs(len[i + 2] - len[i]) <= d && abs(len[j] - len[i + 2]) <= d)){
                            f[i][j] = 2;
                        }
                    }
                }
            }
        }
        for(int i = 1;i <= n;i++){
            for(int j = i + 1;j <= n;j++){
                if(f[i][j] == 1){
                    for(int k = j;k <= n;k++){
                        if(f[k][j] == 2 && f[i][k] != 1){
                            f[i][k] = 2;
                        }
                    }
                }
                else if(f[i][j] == 2){
                    for(int k = j;k <= n;k++){
                        if(f[k][j] == 1){
                            f[i][k] = 2;
                        }
                    }
                }
            }
        }
        long long ans = 0;
        for(int i = 1;i <= n;i++){
            for(int j = 1;j <= n;j++){
                if(f[i][j] == 2){
                    ans++;
                }
            }
        }
        cout << ans << endl;
    }
    return 0;
}
