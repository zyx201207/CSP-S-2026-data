#include<bits/stdc++.h>
#define ll long long
using namespace std;
int n, m, res;
int a[211111];
void f (int x, int steps, int ans){
    if (steps >= m){
        res = max (res, ans);
        return;
    }
    if (x >= n) return;
    f (x+1, steps+1, ans&a[x]);
    f (x+1, steps, ans);
}

int main (){
    freopen ("and.in","r",stdin);
    freopen ("and.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    sort (a+1, a+n+1);
    if (m == 1){
        cout << a[n] << "\n";
        return 0;
    }

    if (m == 2){
        int ans = 0;
        for (int i = 1; i < n; ++i){
            for (int j = i+1; j <= n; ++j){
                ans = max (ans, a[i]&a[j]);
            }
        }
        cout << ans << "\n";
        return 0;
    }

    if (m == n){
        int sum = a[1];
        for (int i = 2; i <= n; ++i) sum + sum&a[i];
        cout << sum << "\n";
        return 0;
    }

    if (m == n-1){
        int ans = 0;
        for (int i = 1; i <= n; ++i){
            int sum = a[1];
            if (i != 1) for (int j = 1; j <= n; ++j){
                if (j == i) continue;
                else sum = sum & a[j];
            }
            if (i == 1){
                sum = a[2];
                for (int j = 3; j <= n; ++j) sum = sum & a[j];
            }
            ans = max (ans, sum);
        }
        cout << ans << "\n";
        return 0;
    }

    set<int>se;
    for (int i = 1; i < 30; ++i) se.insert((1<<i)-1);
    bool flag = 1;
    if (se.find(n-1) != se.end()){
        for (int i = 1; i <= n; ++i) if (a[i]!=i-1){
            flag = 0;
            break;
        }
        if (flag){
            int k2 = 1;
            while (k2 < n) k2 *= 2;
            if (n-k2>=m){
                cout << k2 << "\n";
                return 0;
            }else{
                cout << k2/2 << "\n";
                return 0;
            }
        }
    }

    flag = 1;
    for (int i = 1; i <= n; ++i){
        if (se.find(a[i]) == se.end()){
            flag = 0;
            break;
        }
    }
    if (flag){
        cout << a[n-m+1] << "\n";
        return 0;
    }

    for (int i = 1; i <= n-m+1; ++i){
        f (i, 1, a[i]);
    }
    cout << res << "\n";
    return 0;
}
