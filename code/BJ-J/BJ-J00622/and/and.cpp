#include <bits/stdc++.h>
using namespace std;
int n, m;
int a[200005];
long long cnt;
int main (){
    freopen("and.in", "r", stdin);
    freopen("ans.out", "w", stdout);
    cin >> n >> m;
    for (int i = 1; i <= n; ++i){
        cin >> a[i];
    }
    sort(a + 1, a + n + 1);
    cnt = a[n];
    for (int i = n - 1; i > n - m; --i){
        cnt = cnt & a[i];
    }
    cout << cnt;
    return 0;
}
