#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int N = 5e5 + 10;

int n, ans[N], m, a[N], vis[N];

bool P1(){
    for(int i = 1; i < n; i++){
        if(a[i] > a[i + 1]){
            return 0;
        }
    }
    return 1;
}

int main(){
    freopen("card.in", "r", stdin);
    freopen("card.out", "w", stdout);
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    if(P1()){
        for(int i = 1; i <= n; i++){
            ans[a[i]]++;
        }
        int tmp = 0;
        for(int i = 1; i <= m; i++){
            tmp += ans[i] - 1;
            cout << i + tmp << ' ';
        }
    }else{
        for(int k = 1; k <= n; k++){
            fill(vis + 1, vis + m + 1, 0);
            for(int i = k; i <= n; i++){
                if(vis[a[i]]){
                    //cout << a[i] << '\n';
                    for(int j = vis[a[i]] + 1; j <= i; j++){
                        //cout << a[j] << ' ';
                        vis[a[j]] = 0;
                    }
                    //cout << '\n';
                    vis[a[i]] = i;
                }else{
                    vis[a[i]] = i;
                }
            }
            //cout << "Game:" << k << "-----\n";

            for(int i = 1; i <= m; i++){
                //cout << "Namber:" << i  << ' ' << vis[i] << '\n';
                ans[i] += !(!vis[i]);
            }
            //cout << '\n';
        }
        for(int i = 1; i <= m; i++){
            cout << ans[i] << ' ';
        }
    }
    return 0;
}
/*

4 3
1 2 1 3

10 3
3 1 2 1 3 2 3 1 2 1
*/

