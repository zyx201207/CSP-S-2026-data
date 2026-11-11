#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
long long a[N];
int n, m;
long long dfs(int cnt, long long sum, int sel){
    if(sel == m){
        return sum;
    }
    if(cnt > n){
        return 0;
    }
    return max(dfs(cnt + 1, (sum & a[cnt]), sel + 1), dfs(cnt + 1, sum, sel));
}
int main(){
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);
    cin >> n >> m;
    if(m == n){
        cin >> a[1];
        long long ans = a[1];
        for(int i = 2; i <= n; i++){
            cin >> a[i];
            ans = (ans & a[i]);
        }
        cout << ans;
        return 0;
    }
    if(m == 1){
        long long ans = -1;
        for(int i = 1; i <= n; i++){
            cin >> a[i];
            if(a[i] > ans){
                ans = a[i];
            }
        }
        cout << ans;
        return 0;
    }
    if(m == 2){
        long long ans = -1;
        for(int i = 1; i <= n; i++){
            cin >> a[i];
        }
        for(int i = 1; i <= n; i++){
            for(int j = i + 1; j <= n; j++){
                if((a[i] & a[j]) > ans){
                    ans = (a[i] & a[j]);
                }
            }
        }
        cout << ans;
        return 0;
    }
    if(m == n - 1){
        long long ans = -1;
        for(int i = 1; i <= n; i++){
            cin >> a[i];
        }
        for(int i = 1; i <= n; i++){
            long long cnt = (1LL << 30) - 1;
            for(int j = 1; j <= n; j++){
                if(i == j){
                    continue;
                }
                cnt = (cnt & a[j]);
            }
            if(cnt > ans){
                ans = cnt;
            }
        }
        cout << ans;
        return 0;
    }
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    long long sum = (1LL << 30) - 1;
    cout << dfs(1, sum, 0);
    return 0;
}
