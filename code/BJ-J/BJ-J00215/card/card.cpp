#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
int a[500003], f;
bool p[300005];
int main(){
    freopen("card.in", "r", stdin);
    freopen("card.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    for(int i = n; i >= 1; i--){
        cin >> a[i];
    }
    for(int i = 1; i <= m; i++){
        memset(p, 0, sizeof(p));
        f = 0;
        int cnt;
        for(int j = 1; j <= n; j++){
            if(a[j] == i){
                f++;
                j++;
                while(j <= n){
                    if(p[a[j]]){
                        break;
                    }
                    f++;
                    j++;
                 }
            }
            p[a[j]] = 1;
        }
        cout << f << " ";
    }
    return 0;
}


