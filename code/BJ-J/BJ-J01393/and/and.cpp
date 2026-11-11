

#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

long long a[200009];
int n, m;
long long cnt[59];
string tmp[200009];

bool cmp (int a, int b) {
    return a > b;
};


string turn2 (int num) {
    string s = "";
    while (num) {
        int ans = num % 2;
        s += char(ans + '0');
        num /= 2;
    }
    reverse(s.begin(), s.end());
    string res = "";
    bool ok = false;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] != '0' || ok) {
            res += s[i];
            ok = true;
        }
    }
    reverse(res.begin(), res.end());
    return res;
}

long long turn10 (string s) {
    long long res = 0;
    for (int i = 0; i < s.size(); i++) {
        res += (int)(s[i] - '0') * pow(2, i);
    }
    return res;
}

int main () {
   // cout << turn10("0101") << endl;
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    if (m == 1) {
        long long  maxn = -2e9;
        for (int i = 1; i <= n; i++) {
            maxn = max(maxn, a[i]);
        }
        cout << maxn << endl;
        return 0;
    }
    if (m == n) {
        long long ans = 1;
        for (int i = 1; i <= n; i++) {
            ans = ans & a[i];
        }
        cout << ans << endl;
        return 0;
    }
    if (m == 2) {
        long long maxn = -2e9;
        for (int i = 1; i <= n; i++) {
            for (int j = i + 1; j <= n; j++) {
                long long ans = a[i] & a[j];
                maxn = max(maxn, ans);
                //cout << ans << endl;
            }
        }
        cout << maxn << endl;
        return 0;
    }
    bool ok = true;
    for (int i = 1; i <= n; i++) {
        long long tmp = a[i] + 1;
        if ((int)log2(tmp) != log2(tmp)) {
            ok = false;
            break;
        }
    }
    if (ok) {
        sort(a + 1, a + n + 1, cmp);
        cout << a[m] << endl;
        return 0;
    }

    ok = false;
    for (int i = 1; i <= n; i++) {
        if (a[i] >= 4) {
            ok = true;
        }
    }
    if (!ok) {
        sort(a + 1, a + n + 1, cmp);
        if (a[m] < 1) {
            cout << 0 << endl;
            return 0;
        }

        if (a[m] == 3) {
            cout << 3 << endl;
            return 0;
        }
        if (a[m] == 2) {
            cout << 2 << endl;
            return 0;
        }

        int cnt1 = 0, cnt3 = 0;
        for (int i = 1; i <= n; i++) {
            if (a[i] == 1) {
                cnt1++;
            }else if (a[i] == 3) {
                cnt3++;
            }
        }
        if (cnt1 + cnt3 >= m) {
            cout << 1 << endl;
            return 0;
        }else{
            cout << 0 << endl;
            return 0;
        }
    }
    
    


    long long ans = 1;
    sort(a + 1, a + n + 1, cmp);
    for (int i = n; i >= 1; i--) {
        ans = ans & a[i];
    }
    cout << ans << endl;
    return 0;
}