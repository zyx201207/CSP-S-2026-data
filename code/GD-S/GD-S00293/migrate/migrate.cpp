#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn = 2000005;
int a[maxn], l[maxn], r[maxn], sum[maxn];
vector<int> now;
signed main(){
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int c, t;
    cin >> c >> t;
    while(t--){
        int n, d, ans = 0;
        cin >> n >> d;
        for(int i = 1;i <= n;i++) cin >> a[i];
        int st = n;
        for(int i = n;i >= 1;i--){
            while(a[st] - a[i] > d) st--;
            r[i] = st;
        }
        st = 1;
        for(int i = 1;i <= n;i++){
            while(a[i] - a[st] > d) st++;
            l[i] = st;
        }
        if(n <= 8000){
            for(int i = 1;i <= n;i++){
                int p = i;
                sum[i] = 1;
                for(int j = i + 1;j <= n;j++){
                    if(j > r[p]){
                        p = r[p];
                        now.push_back(p);
                    } 
                    // int sum = 1, g = j;
                    // for(int k = now.size() - 1;k >= 0;k--){
                    //     g = l[g];
                    //     sum = sum * (now[k] - g + 1);
                    //     if(sum > 2) break;
                    // }
                    sum[j] = 1;
                    if(now.size()){
                        if(now[now.size() - 1] - j + 1 > 2 || sum[l[j]] > 2) sum[j] = 3;
                        else sum[j] = sum[l[j]] * (now[now.size() - 1] - l[j] + 1);
                        // if(now.back() == j && sum[j] > 2) break;
                    }
                    // if(sum[j] == 2){
                    //     cout << i << ' ' << j << ' ' << l[j] << "-----" << endl;
                    //     for(int k : now) cout << k << ' ';
                    //     cout << endl;
                    //     // cout << endl << sum[j] << ' ' << sum[l[j]] << endl;
                    // }
                    // cout << i << ' ' << j << "-----" << endl;
                    // for(int k : now) cout << k << ' ';
                    // cout << endl << sum[j] << ' ' << sum[l[j]] << endl;
                    ans += (sum[j] == 2);
                }
                now.clear();
            }
            cout << ans << "\n";
        }else{
            int nd = a[2] - a[1], p = 1;
            for(int i = 2;i <= n;i++){
                if(a[i] - a[i - 1] != nd){
                    p = 0;
                    break;
                }
            }
            if(p){
                int dd = r[1] - 1;
                // cout << dd << endl;
                if(dd <= 1) cout << 0 << "\n";
                else cout << max(0ll, n - dd * 2 + 1) << "\n";
            }else{
                if(a[1] + d * 2 >= a[n]){
                    for(int i = 1;i <= n;i++){
                        int to = r[i];
                        if(to <= i + 1) continue;
                        ans += max(0ll, r[to - 1] - r[to - 2]);
                        // cout << i << ' ' << max(0ll, r[to - 1] - r[to - 2]) << endl;
                    }
                    cout << ans << "\n";
                }else if(a[1] + d * 10 >= a[n]){
                    for(int i = 1;i <= n;i++){
                        int p = 1, lt = i;
                        // cout << i << "-----" << endl;
                        for(int j = r[i];j < n;j = r[j]){
                            if(r[j] == j) break;
                            if(p){
                                if(j > lt + 1) ans += max(0ll, r[j - 1] - r[j - 2]);
                            }
                            if(!p) ans += max(0ll, r[j] - r[j - 1]);
                            // cout << j << ' ' << lt << ' ' << ans << endl;
                            if(j - l[r[j]] + 1 > 2 || (j - l[r[j]] + 1 > 1 && !p)) break;
                            if(j - l[r[j]] + 1 > 1) p = 0;
                            lt = j;
                        }
                        now.clear();
                    }
                    cout << ans << "\n";
                }else{
                    for(int i = 1;i <= n;i++){
                        int p = i;
                        sum[i] = 1;
                        for(int j = i + 1;j <= n;j++){
                            if(j > r[p]){
                                p = r[p];
                                now.push_back(p);
                            } 
                            sum[j] = 1;
                            if(now.size()){
                                if(now[now.size() - 1] - j + 1 > 2 || sum[l[j]] > 2) sum[j] = 3;
                                else sum[j] = sum[l[j]] * (now[now.size() - 1] - l[j] + 1);
                                if(now.back() == j && sum[j] > 2) break;
                            }
                            ans += (sum[j] == 2);
                        }
                        now.clear();
                    }
                    cout << ans << "\n";
                }
            }
        }
        // return 0;
    }
    return 0;
}