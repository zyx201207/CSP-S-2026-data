#include<bits/stdc++.h>
using namespace std;
const int N = 505;
const int M = 5e5+5;
int w[M],a[N][M],t[N][M];
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    int c,n,m,d,q,o,x,y;
    cin >> c >> n >> m >> d >> q;
    for(int i=1;i<=m;i++)
        cin >> w[i];
    int sum = 0,num = 0;
    for(int i=1;i<=n;i++){
        cin >> o;
        num += o;
        for(int j=1;j<=o;j++){
            cin >> a[i][j] >> t[i][a[i][j]];
            sum += t[i][a[i][j]];
        }
    }
    int mid = sum / num;
    while(q--){
        cin >> x >> y;
        int ans = 2e9;
        for(int i=1;i<=n;i++){
            if(t[i][x] != 0 && t[i][y] != 0)
                ans = min(ans,t[i][x] + t[i][y]);
        }
        if(ans <= 3*mid){
            cout << w[x] + ans + w[y] << endl;
            continue;
        }
        for(int i=1;i<=n;i++){
            if(t[i][x] != 0){
                for(int j=1;j<=n;j++){
                    if(t[j][y] != 0){
                        for(int k=1;k<=m;k++){
                            if(t[i][k] != 0 && t[j][k] != 0)
ans = min(ans,t[i][x] + t[i][k] + t[j][k] + t[j][y]);
                        }
                    }
                }
            }
        }
        if(ans <= 7*mid){
            cout << w[x] + ans + w[y] << endl;
            continue;
        }
        for(int i=1;i<=n;i++){
            if(t[i][x] != 0){
                for(int j=1;j<=n;j++){
                    if(t[j][y] != 0){
                        for(int k=1;k<=m;k++){
                            if(t[i][k] != 0){
                                for(int l=1;l<=n;l++){
                                    if(t[l][k] != 0){
                                        for(int p=1;p<=m;p++){
                                            if(t[l][p] != 0 && t[j][p] != 0)
                                                ans = min(ans,t[i][x] + t[i][k] + t[l][k] + t[l][p] + t[j][p] + t[j][y]);
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        if(ans <= 20*mid){
            cout << w[x] + ans + w[y] << endl;
            continue;
        }
        for(int i=1;i<=n;i++){
            if(t[i][x] != 0){
                for(int j=1;j<=n;j++){
                    if(t[j][y] != 0){
                        for(int k=1;k<=m;k++){
                            if(t[i][k] != 0){
                                for(int l=1;l<=n;l++){
                                    if(t[l][k] != 0){
                                        for(int p=1;p<=m;l++){
                                            if(t[l][p] != 0){
                                                for(int z=1;z<=n;z++){
                                                    if(t[z][p] != 0){
                                                        for(int b=1;b<=m;b++){
                                                            if(t[z][b] != 0 && t[j][b] != 0)
                                                                ans = min(ans,t[i][x] + t[i][k] + t[l][k] + t[l][p] + t[z][p] + t[z][b] + t[j][b]+ t[j][y]);
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        if(ans != 2e9){
            cout << w[x] + ans + w[y] << endl;
            continue;
        }
        cout << 0;
    }
    return 0;
}