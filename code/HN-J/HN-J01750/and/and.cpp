#include<bits/stdc++.h>

using namespace std;
using ll = long long;

const int N = 2e5 + 10;

int n, m, a[N], log_2[31];

namespace subtaskm_1{
    int ans;

    void solve(){
        ans = 0;
        for(int i = 1; i <= n; i++){
            ans = max(ans, a[i]);
        }
        cout << ans;
    }
}

namespace subtaskm_2{
    int ans;

    void solve(){
        ans = 0;
        for(int i = 1; i <= n; i++){
            for(int j = i + 1; j <= n; j++){
                ans = max(ans, a[i] & a[j]);
            }
        }
        cout << ans;
    }
}

namespace subtaskm_n{
    int ans;

    void solve(){
        ans = a[1];
        for(int i = 2; i <= n; i++){
            ans &= a[i];
        }
        cout << ans;
    }
}

namespace subtaskm_n_1{
    int pre[N], suf[N], ans;

    void solve(){
        pre[1] = a[1];
        for(int i = 2; i <= n; i++){
            pre[i] = pre[i - 1] & a[i];
        }
        suf[n] = a[n];
        for(int i = n - 1; i >= 1; i--){
            suf[i] = suf[i + 1] & a[i];
        }
        ans = 0;
        for(int i = 1; i <= n; i++){
            ans = max(ans, pre[i - 1] & suf[i + 1]);
        }
        cout << ans;
    }
}

namespace special_A{
    void solve(){
        sort(a + 1, a + n + 1, greater<int>());
        cout << a[m];
    }
}

namespace special_B{
    int ans;

    void solve(){
        ans = a[n];
        for(int i = n - 1; i >= n - m + 1; i--){
            ans &= a[i];
        }
        cout << ans;
    }
}

namespace subtask_a{
    int cnt[4];

    void solve(){
        cnt[0] = cnt[1] = cnt[2] = cnt[3] = 0;
        for(int i = 1; i <= n; i++){
            cnt[a[i]]++;
        }
        if(cnt[3] >= m){
            cout << 3;
        } else if(cnt[3] + cnt[2] >= m){
            cout << 2;
        } else if(cnt[3] + cnt[1] >= m){
            cout << 1;
        } else{
            cout << 0;
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);
    cin >> n >> m;
    bool sp_A = true, sp_B = true, a_4 = true;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        if(a[i] != i - 1) sp_B = false;
        if(a[i] >= 4) a_4 = false;
    }
    log_2[0] = 1;
    for(int i = 1; i <= 30; i++){
        log_2[i] = log_2[i - 1] * 2;
    }
    for(int i = 1; i <= n; i++){
        bool f = false;
        for(int j = 0; j <= 30; j++){
            if(a[i] + 1 == log_2[j]){
                f = true;
                break;
            }
        }
        sp_A = f;
        if(sp_A == false){
            break;
        }
    }
    if(sp_B == true){
        sp_B = false;
        for(int i = 0; i <= 30; i++){
            if(n == log_2[i]){
                sp_B = true;
                break;
            }
        }
    }
    if(m == 1){
        subtaskm_1::solve();
    } else if(m == 2){
        subtaskm_2::solve();
    } else if(m == n){
        subtaskm_n::solve();
    } else if(m == n - 1){
        subtaskm_n_1::solve();
    } else if(sp_A == true){
        special_A::solve();
    } else if(sp_B == true){
        special_B::solve();
    } else if(a_4 == true){
        subtask_a::solve();
    }
    return 0;
}
