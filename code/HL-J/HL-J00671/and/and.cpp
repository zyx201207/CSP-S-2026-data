#include<bits/stdc++.h>
using namespace std;
int m, n, a[200005], maxx;
int main(){
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    if(m == 2){
        for(int i = 1; i <= n; i++){
            for(int j = i + 1; j <= n; j++){
                maxx = max(maxx, a[i] & a[j]);
            }
        }
    }
    else{
        for(int i = 1; i <= n; i++){
            for(int j = i + 1; j <= n; j++){
                for(int k = j + 1; k <= n; k++){
                    maxx = max(maxx, a[i] & a[j] & a[k]);
                }
            }
        }
    }
    cout << maxx;
    return 0;
}
//Trick||Treat!
