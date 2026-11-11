#include <bits/stdc++.h>
using namespace std;


typedef long long ll;
const int N = 1e5 + 5, M = 5005;
ll n, m, a[M], sum, ans = 0, d[M], t[M], f[M];
bool b = 1;

void solveB() {
    ll mid = (n + 1) / 2;
    for(int i =1 ; i <= n; i++) {
        d[i] = abs(a[i] - a[mid]);
    }

    sort(d + 1, d + n + 1);

    ll sum = 0;
    for(int i = 1; i <= n; i++) {
        //cout << d[i] << " ";
        sum += d[i];
        if(sum > m) break;
        ans++;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);

    cin >> n >> m;
    ll mid = (1 + n) / 2;
    for(int i =1 ; i <= n; i++) {
        cin >> a[i];
    }

    for(int i = n; i >= 1; i--) {
        t[i] = a[i] - a[i - 1];
    }

    for(int i = 1; i < n; i++) {
        if(t[i] != t[i - 1]) b = 0;
    }
    //cout << "b" << endl;
    ll tmp;
    if(n <= 5000) {
        for(int i = 1; i <= n; i++) {
            ll cnt = 0;
            tmp = 0;
            memset(f, 0, sizeof(f));
            for(int j = 1; j <= n; j++) {
                f[j] = abs(a[i] - a[j]);
                //cout << f[i] << " ";
            }
            sort(f + 1, f + n + 1);
            for(int i = 1; cnt <= m || i <= n; i++) {
                cnt += f[i];
                tmp++;
            }
            //cout << endl;
        }
        ans = max(ans, tmp);
    }
    else {
        solveB();
    }
    cout << ans << endl;

    //sum = a[2] - a[1];

    //while(sum > m) {
    //    sum *= 2;
    //    ans++;
    //}

    //cout << ans << endl;
    //sort(a + 1, a + n + 1);
    //(int i =1 ; i <= n; i++) {
    //    cout << a[i];
    //}

    return 0;
}
