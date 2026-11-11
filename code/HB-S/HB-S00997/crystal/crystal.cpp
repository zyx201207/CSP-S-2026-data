#include <bits/stdc++.h>
using namespace std;
#define ull unsigned long long
#define ll long long
ull n, m;
ll nmin = 1e13, nmax = 1e13;
long long zyf[500005];
ull sp[500005];
int text[10000];
ull ans;
int dfs(int rem, ull sum, ull num) {
    if (sum == n + 1) {
        if (num > ans) 
            ans = num;
        // if (num == 3 || num != 3) {
        //     for (ull i = 1; i < sum; i++) {
        //         cout << text[i] << ' ';
        //     }
        //     cout << num;
        //     cout << '\n';
        // }       
        return 0;
    }
    for (int i = 0; i <= rem; i++) {
        int a = zyf[sum] + i;
        text[sum] = i;
        if (i == 0) {
            dfs(rem, sum + 1, num);
            continue;
        }
        // if (sum == 1 && a == 4) {
        //     cout << sp[a] << ' ';
        // }
        if (sp[a] != 0) {
            sp[a]++;
            sp[zyf[sum]]--;
            if (sp[a] > num)
                dfs(rem - i, sum + 1, sp[a]);
            else
                dfs(rem - i, sum + 1, num);
            sp[a]--;
            sp[zyf[sum]]++;
        }
        else {
            sp[a]++;
            sp[zyf[sum]]--;
            dfs(rem - i, sum + 1, num);
            sp[a]--;
            sp[zyf[sum]]++;
        }
    }
    return 0;
}
inline ll read() {
    int x = 0, f = 1; char ch = getchar();
    while(ch < '0' || ch > '9') {if (ch == '-') f = -1; ch = getchar();}
    while (ch >= '0' && ch <= '9') {x = x * 10 + ch - 48; ch = getchar();}
    return x * f;
}
int main() {
    // bool flag = 1;
    nmax = -nmax;
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    n = read(), m = read();
    for (ull i = 1; i <= n; i++){
        ll a;
        a = read();
        // if (a != i)
        //     flag = 0;
        sp[a]++;
        zyf[i] = a;
        if (a < nmin)
            nmin = a;
        if (a > nmax)
            nmax = a;
    }
    // if (flag == 1) {

    // }
    dfs(m, 1, 0);
    cout << ans;
    return 0;
}
