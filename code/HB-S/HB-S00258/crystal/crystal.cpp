#include<bits/stdc++.h>
using namespace std;

#define ll long long

const int N = 5 * 1e5 + 5;
int n;
ll m, a[N], sum[N], ans = INT_MIN;

int main(){
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    a[0] = 0;
    bool b = 1;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        if(a[i] != i) b = 0;
        
    }
    if(b == 1) {
        int i = 0;
        ll cnt = 0;
        for(i = 1;i <= n; i++){
            if(cnt > m) break;
            cnt += i;
        }
        cout << i - 1 << endl;
        return 0;
    }



    sort(a + 1, a + n + 1);
    for(int i = 1; i <= n; i++){
        ll cnt = 0;
        int j = i + 1;
        while (cnt <= m && j <= n)
        {
            cnt = cnt + ((a[j] - a[j - 1]) * (j - i));
            if(cnt > m) break;
            j++;
        }
        
        ans = max(ans, (ll)(j - i));
    }
    cout << ans << '\n';
    return 0;
}