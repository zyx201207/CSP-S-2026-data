#include <bits/stdc++.h>

using namespace std;
const int maxn = 5e3 + 10;
long long a[maxn], cnt[maxn];
long long sum = 0;
long long ans = 0;

long long n, m;
/*void dfs(int x){
    while (sum <= m){
        cnt[x]++;
        if (a[x] == a[x + 1]){
            sum += cnt[x];
        }
        for (int i = 1; i <= n; i++){
            if (cnt[i] != 0){
            ans++;
            }
        }
        dfs(x + 1);
    }
    cout << ans;
}
*/
int main(){
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    cin >> n >> m;
    /*for (int i = 1; i <= n; i++){
        cin >> a[i];
    }
    sort(a + 1, a + 1 + n);
    */
    if (m % 2 == 1){
        cout << (m + 1) / 2;
    }
    else if (m % 2 == 0){
        cout << m / 2;
    }

    //dfs(1);
    return 0;
}
