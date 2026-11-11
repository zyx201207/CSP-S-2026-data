
#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N = 2e5 + 5;
int n, ans, a[N];
char c[N];

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);

    cin >> n;
    for(int i = 1;i <= n;i++){
        cin >> a[i] >> c[i];
    }
    int i = 1, j = n;
    while(1){
        while(i <= n && a[i] == 0) i++;
        while(j >= 1 && a[j] == 0) j--;
        if(i > n || j < 1) break;
        if(a[i] >= a[j]){
            if(c[i] == c[j]) a[i] -= a[j], a[j] = 0;
            else ans += a[j], a[i] -= a[j], a[j] = 0;
        } else {
            if(c[i] == c[j]) a[j] -= a[i], a[i] = 0;
            else ans += a[i], a[j] -= a[i], a[i] = 0;
        }
    }
    cout << ans << '\n';


    return 0;
}
