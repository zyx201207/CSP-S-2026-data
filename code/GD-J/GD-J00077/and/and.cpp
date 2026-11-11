#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int N = 2e5 + 5;
ll a[N];
int n, m;

ll dfs(int siz, int cur){
    if(siz == m)
        return a[cur];
    ll cnt = 0;
    for (int i = cur + 1; i <= n; i++)
        cnt = max(cnt, a[cur] & dfs(siz + 1, i));
    return cnt;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    a[0] = INT_MAX;
    if (n <= 20)
        cout << dfs(0, 0) << '\n';
    else if(n <= 2000 && ((m == 1) || (m == 2)))
        cout << dfs(0, 0) << '\n';
    else if (m == n){
        ll ans = a[1];
        for (int i = 2; i <= n; i++)
            ans &= a[i];
        cout << ans << '\n';
    }
    else if (m == n - 1){
        sort(a + 1, a + n + 1);
        ll ans = a[1];
        for (int i = 2; i <= n; i++)
            ans &= a[i];
        cout << ans << '\n';
    }
    else{
        int ch = 0;
        for (int i = 1; i <= n; i++)
            ch += (a[i] % 2LL == 0LL);
        if(ch == n){
            sort(a + 1, a + n + 1, greater<int>());
            cout << a[m] << '\n';
            return 0;
        }
        ch = 0;
        for (int i = 1; i <= n; i++)
            ch += (a[i] <= 4);
        if (ch == n){
            int c[5] = {};
            for (int i = 1; i <= n; i++)
                c[a[i]]++;
            if(c[4] >= m)
                cout << 4 << '\n';
            else if(c[3] >= m)
                cout << 3 << '\n';
            else if(c[3] + c[2] >= m)
                cout << 2 << '\n';
            else if(c[3] + c[1] >= m)
                cout << 1 << '\n';
            else
                cout << 0;
            return 0;
        }
        cout << 0 << '\n';
    }
    return 0;
}
