#include <bits/stdc++.h>
using namespace std;
int a[110][110];
int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    int c,t;
    cin >> c >> t;
    while(t--){
        int n,k;
        cin >> n >> k;
        for(int i = 1;i <= k; i++){
            int x,y;
            cin >> x >> y;
            a[x][y]++;
        }
        int max_n = 0;
        for(int i = 1;i <= 110; i++){
            for(int j = 1;j <= n; j++){
                max_n = max(max_n, a[i][j]);
            }
        }
        cout << max_n;
    }
    return 0;
}
