#include<bits/stdc++.h>
using namespace std;

long long m, n, ans = 0;
int a[200005] = { };

int main(){
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    sort(a+1, a+n+1, greater<int>());
    ans = a[1] & a[2];
    for(int i = 2; i <= m; i++){
        ans = a[i] & ans;
    }
    cout << ans;
    return 0;
}
