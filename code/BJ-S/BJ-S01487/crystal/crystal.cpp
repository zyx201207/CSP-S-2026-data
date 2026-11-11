#include<bits/stdc++.h>
using namespace std;
long long n, m, ans = INT_MIN, sum, a[500010];
int main(){
    cin.tie(nullptr) -> sync_with_stdio(0);
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    sort(a + 1, a + n + 1);
    //specail A
    bool flag = 1;
    for(int i = 1; i <= n; i++){
        if(a[i] != i){
            flag = 0;
        }
    }
    if(flag){
        cout << min(m + 1, n);
        return 0;
    }
    //specail B
    flag = 1;
    int x = a[2] - a[1];
    for(int i = 3; i <= n; i++){
        if(a[i] - a[i - 1] != x){
            flag = 0;
        }
    }
    if(flag){
        cout << min(n, m / x + 1);
        return 0;
    }
    for(int i = 1; i <= n; i++){
        sum = 0;
        for(int j = i; j >= 0; j--){
            if(a[i] - a[j] <= m){
                sum++;
                m -= a[i];
                m += a[j];
                continue;
            }
            break;
        }
        ans = max(ans, sum);
    }
    cout << ans;
    return 0;
}

