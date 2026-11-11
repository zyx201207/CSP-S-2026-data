#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll N = 2e5 + 10;
int n, a[N];
ll ans;
char c[N];
int main(){
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    cin >> n;
    for(int i = 1; i <= n; i ++){
        cin >> a[i] >> c[i];
    }
    int j = n;
    for(int i = 1; i <= n && i < j; i ++){
        int t = a[i];
        while(a[j] < t){
            if(c[i] != c[j]){
                ans += a[j];
            }
            t -= a[j --];
        }
        a[j] -= t;
        if(c[i] != c[j]) ans += t;
    }
    cout << ans << endl;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
