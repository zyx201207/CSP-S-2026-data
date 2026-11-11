#include<bits/stdc++.h>
using namespace std;
const long long N = 5e5 + 10;
long long n, m, a[N], ans;
int main(){
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    sort(a + 1, a + n + 1);
    for(int i = 1; i <= n; i++){
        long long x = m, t = 1;
        for(int j = i - 1; j >= 1; j--){
            if(x >= (a[i] - a[j])){
                x -= (a[i] - a[j]);
                t++;
            }
            else break;
        }
        ans = max(ans, t);
    }
    cout << ans;
    return 0;
}
