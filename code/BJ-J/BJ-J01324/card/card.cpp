#include <bits/stdc++.h>
using namespace std;
long long n, m, a[500005], w[300005] = {0}, nx[500005], ans[300005] = {0};
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    freopen("card.in", "r", stdin);
    freopen("card.out", "w", stdout);
    cin >> n >> m;
    for(int i = 1;i <= n;i ++){
        cin >> a[i];
        nx[w[a[i]]] = i;
        nx[i] = i + 1;
        w[a[i]] = i;
    }
    for(int i = 1;i <= n;i ++){
        memset(w, 0, sizeof(w));
        for(int j = i;j <= n;j ++){
            if(w[a[j]] == 0){
                ans[a[j]] ++;
                w[a[j]] = 1;
            }
            j = nx[j] - 1;
        }
    }
    for(int i = 1;i <= m;i ++){
        cout << ans[i] << " ";
    }
    return 0;
}
