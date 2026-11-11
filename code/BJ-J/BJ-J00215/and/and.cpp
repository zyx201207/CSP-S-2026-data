#include <iostream>
#include <algorithm>
using namespace std;
long long a[200003];
bool cmp(long long x, long long y){
    return x > y;
}
int main(){
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    sort(a+1, a+n+1, cmp);
    long long ans = 0, cnt = a[1];
    if(m == 2){
        for(int i = 1; i <= n-1; i++){
            for(int j = i+1; j <= n; j++){
                ans = max(ans, a[i]&a[j]);
            }
        }
        cout << ans << endl;
        return 0;
    }
    for(int i = 2; i <= m; i++){
        cnt &= a[i];
    }
    ans = max(ans, cnt);
    for(int l = 1, r = m+1; r <= n; l++, r++){
        cnt ^= a[l];
        cnt &= a[r];
        ans = max(ans, cnt);
    }
    cout << ans << endl;
    return 0;
}


