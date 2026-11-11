#include <bits/stdc++.h>
using namespace std;
int a[200010];
int main(){
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);
    int n, m;
    cin >> n >> m;
    int t = 0, maxn = 0;
    for(int i = 1;i <= n;i++){
            cin >> a[i];
            maxn = max(a[i], maxn);
            t &= a[i];
    }
    if(m == 1){
        cout << maxn;
    }
    if(m == n)cout << t;
    return 0;
}
