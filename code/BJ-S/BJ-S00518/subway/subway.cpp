#include<bits/stdc++.h>
using namespace std;
const int N = 505;
const int K = 5e5+5;
int c,n,m,d,q,k,x,y,A,T,z,w[N],a[N][K],t[N][K],mn[N][N];
int main(){
    freopen("subway5.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin >> c >> n >> m >> d >> q;
    if(12 <= c && c <= 19){
        for(int i = 1;i <= m;i++) cin >> w[i];
        for(int i = 1;i <= n;i++){
            cin >> k;
            for(int j = 1;j <= k;j++){
                cin >> A >> T;
                a[i][j] = A;
                for(int k = 1;k <= j;k++){
                    mn[a[i][k]][A] = 0;
                }
            }
        }
        memset(mn,0x3f,sizeof(mn));
        for(int i = 1;i <= n;i++){
            for(int j = i;j <= n;j++){
                for(int k = i;k <= j;k++){
                    if(mn[i][k] + mn[k][j] < mn[i][j]){
                        mn[i][j] = mn[i][k]+mn[k][j];
                    }
                }
            }
        }
        while(q--){
            cin >> x >> y;
            cout << w[x] + w[y] + mn[x][y] << '\n';
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}