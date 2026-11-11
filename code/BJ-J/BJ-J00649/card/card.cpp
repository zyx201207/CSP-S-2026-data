#include <bits/stdc++.h>
using namespace std;
const int MAXn = 500010;
int main(){
    int n, m, a[MAXn], same, b[100];
    bool flag = 0;
    map <int, int> mp;
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }for(int j = 1; j <= n; j++){
        mp.clear();
        for(int k = j; k <= n; k++){
            for(int o = j; o < k; o++){
                if(a[k] == a[o]){
                    flag = 1;
                    same = o;
                    break;
                }
            }
            if(flag && !(mp.empty())){
                for(int p = mp[same]; p <= mp.size(); p++){
                    mp.erase(mp[p]);
                }
            }
            mp[k] = a[k];
        }
        for(int l = 1; l <= mp.size(); l++){
            if(mp[l]){
                b[mp[l]]++;
            }
        }
    }
    for(int x = 1; x <= m; x++){
        cout << b[x] << " ";
    }
    return 0;
}
