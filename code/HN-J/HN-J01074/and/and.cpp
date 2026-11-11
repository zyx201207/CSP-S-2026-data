#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int N = 2e5 + 10;

ll n, m, a[N], ans;

void dfs(int x, int cnt, ll sum){
    if(x == n + 1){
        if(cnt == m){
            ans = max(ans, sum);
        }
        return ;
    }
    dfs(x + 1, cnt + 1, (sum == -1 ? a[x] : sum & a[x]));
    dfs(x + 1, cnt, sum);
}

bool P1(){
    ll tmp = 1;
    while(tmp < n){
        tmp *= 2;
    }
    if(tmp != n){
        //return 0;
    }
    for(int i = 1; i <= n; i++){
        if(a[i] != i - 1){
            return 0;
        }
    }
    return 1;
}

int main(){
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> n >> m;
    ll mx = 0;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        mx = max(mx, a[i]);
    }
    if(m == 1){
        cout << mx;
    }else if(m == 2){
        mx = 0;
        for(int i = 1; i <= n; i++){
            for(int j = i + 1; j <= n; j++){
                mx = max(mx, a[i] & a[j]);
            }
        }
        cout << mx;
    }else if(m == n){
        mx = a[1];
        for(int i = 2; i <= n; i++){
            mx &= a[i];
        }
        cout << mx;
    }else if(P1()){
        if(m * 2 > n){
            cout << 0;
        }else{
            if(m == 2){
                cout << (a[n] & a[n - 1]);
            }else{/*
                int tmp = a[n] & a[n - 1];
                int pos = n - 3;
                m -= 2;
                while(pos && m){
                    tmp &= a[pos];
                    m--;
                    pos--;
                }
                cout << tmp;*/
                cout << a[n - 4];
            }
        }
    }else{
        dfs(1, 0, -1);
        cout << ans;
    }
    return 0;
}
/*


8 5
0 1 2 3 4 5 6 7

16 3
0 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15

14 3
0 1 2 3 4 5 6 7 8 9 10 11 12 13


n - 2

n - 4

*/
