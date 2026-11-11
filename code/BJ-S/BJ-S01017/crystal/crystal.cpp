#include <bits/stdc++.h>
using namespace std;

const int maxn = 2e6 + 10;
int a[maxn], b[maxn];

bool dengcha(int n){
    int x = a[2] - a[1];
    for (int i = 3; i <= n; i ++){
        if (a[i] - a[i - 1] != x) return 0;
    }
    return 1;
}

bool cmp(int a, int b){
    return a < b;
}

int f(int x, int n, int m){

    int r = x, l = x, sum = b[l], ans = 1;
    while (sum <= m){
        ans ++;
        if (l - 1 < 1 || b[r + 1] < b[l - 1] && r + 1 <= n - 1){
            r += 1;
            sum += b[r];
        }else if (r + 1 > n - 1 || b[r + 1] >= b[l - 1] && l - 1 >= 1){
            l -= 1;
            sum += b[l];
        }
        if (r + 1 > n - 1 && l - 1 < 1) break;
        //cout << b[l] << " " << b[r] << " " << ans << " " << sum << "  " << l << " " << r << endl;
    }
    return ans;
}

void solve(){
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i ++){
        cin >> a[i];
    }

    sort(a, a + n, cmp);
    if (dengcha(n)){//A B
        int ans = 0, num = 0, cha = a[2] - a[1];
        for (int i = 1; i <= n; i ++){
            if (num + i * cha <= m) num += i * cha;
            else {
                ans = i;
                break;
            }
        }
        cout << ans;
        return ;
    }

    for (int i = 2; i <= n; i ++){
        b[i - 1] = a[i] - a[i - 1];
    }

    int ans = 0;
    for (int i = 1; i <= n - 1; i ++){
        ans = max(ans, f(i, n, m));
    }
    cout << ans;
    return ;

}

int main(){
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);

    solve();
}
