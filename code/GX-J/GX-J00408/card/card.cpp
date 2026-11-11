#include<bits/stdc++.h>
using namespace std;
long long n, m;
int a[1000005], x[1000005];
int main(){

    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;
    for(int i = 1; i <= n; i ++){
        cin >> a[i];
    }
    sort(a + 1, a + 1 + n);
    for(int i = 1; i <= n; i ++){
        x[a[i]] ++;
    }
    for(int i = 1; i <= m; i ++){
        cout << x[i] << " ";
    }
    return 0;
}
