#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 5;
long long n, m, a[N];
bool cmp(int x, int y){
    return x < y;
}
int main(){
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    cin >> n >> m;
    for (int i = 1;i <= n;++ i) cin >> a[i];
    sort (a + 1, a + n + 1, cmp);
    long long res = 0;
    for (int i = 1;i <= n;++ i){
        long long cnt = 1, sum = m;
        for (int j = i - 1;j >= 1;-- j){
            if (sum < a[i] - a[j]) break;
            cnt ++;
            sum -= (a[i] - a[j]);
        }
        res = max (res, cnt);
    }
    cout << res;
    return 0;
}
