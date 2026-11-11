#include<bits/stdc++.h>
using namespace std;
#define ine long long
const int Maxn = 5e5 + 5;
int a[Maxn];
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    int n, m;
    cin >> n >> m;
    if(n > 5005){
        for(int i = 1; i <= n; i++){
            cin >> a[i];
        }
        sort(a + 1, a + n + 1);
        long long anspian = 1;
        for(int i = n - 1; i >= 1; i--){
            if(m <= a[n] - a[i]){
                m -= a[n] - a[i];
                anspian++;
            }
        }
        cout << anspian;
        return 0;
    }
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    sort(a + 1, a + n + 1);
    int ans = 1;
    for(int i = n; i > 1; i--){
        int cnt = 0;
        for(int j = i; j > 1; j--){
            cnt += a[i] - a[j];
            if(cnt > m){
                cnt = i - j;
                //cout << i << " " << cnt;
                break;
            }
            if(j == 2){
                cnt = i;
            }
        }
        ans = max(ans, cnt);
    }
    cout << ans;
    return 0;
}
