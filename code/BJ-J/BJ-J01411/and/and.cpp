#include <bits/stdc++.h>
using namespace std;
long long a[200010];
int main(){
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);

    int n, m; cin >> n >> m;

    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    cout << m << "\n";
    if(m == 1){
        long long maxn = -100000;
        for(int i = 1; i <= n; i++){
            maxn = max(maxn, a[i]);
        }
        cout << maxn << "\n";
    }
    else if(m == 2){
        long long maxn = -100000;
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                    if(i == j) continue;
                maxn = max(maxn, a[i] & a[j]);
                //cout << a[i] << " " << a[j] << " " << (a[i] & a[j]) << "\n";
            }
        }
        cout << maxn << "\n";
    }
    else if(m == n){
        int maxn = a[1];
        for(int i = 2; i <= n; i++){
            maxn = maxn & a[i];
        }
        cout << maxn << "\n";
    }

    return 0;
}
