#include <bits/stdc++.h>
using namespace std;
long long a[500005], last[300005], cnt[300005];
int main(){
    freopen("card.in", "r", stdin);
    freopen("card.out", "w", stdout);
    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        last[a[i]] = i;
    }
    for(int i = 1; i <= n; i++){
        int j = i;
        while(j <= n){
            // cout << a[j] << " ";
            cnt[a[j]]++;
            j = last[a[j]] + 1;
            // cout << j - 1 << endl;
        }
        // cout << endl;
    }
    for(int i = 1; i <= m; i++){
        cout << cnt[i] << " ";
    }
    return 0;
}