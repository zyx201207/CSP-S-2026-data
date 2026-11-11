#include <bits/stdc++.h>
using namespace std;
int n, ans;
long long m, t[500005], cnt;
int main(){
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    cin >> n >> m;
    for (int i = 1; i <= n; i++){
        cin >> t[i];
    }
    sort(t + 1, t + n + 1);
//    long long tt = 0;
//    for (int i = 1; i <= n; i++){
//        cout << t[i] << "\n";
//        tt += abs(t[i] - t[1500]);
//    }
//    cout << "--------------------" << tt<< "\n";
    int l = 1;
    for (int i = 1; i <= n; i++){
        cnt += t[i] - t[i - 1];
        cnt += (i - l) * (t[i] - t[i - 1]);
        while(cnt > m) cnt -= t[i] - t[l], l++;
        l = min(l, i);
        ans = max(ans, i - l + 1);
    }
    cout << ans;
    return 0;
}
