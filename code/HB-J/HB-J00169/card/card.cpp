#include<bits/stdc++.h>
using namespace std;
const int N = 3e5+5;
int n;int m;
int a[N];
int cnt[N];
void solve(int t) {
    vector<int>now(n + 1);
    vector<int>tmp(n + 1);
    int tot = 0;
    for (int i = t ; i <= n; i++) {
        
        tmp.clear();
        for (int k = 1; k <= tot;k++) {
            if (now[k] == a[i]) {
                for (int j = 0;j <k;j ++) {
                    tmp.push_back(now[j]);
                }
                // cout << "k" << k << endl;
                tot = k - 1;
                swap(now, tmp);
                break; 
            }
        }
        // cout << a[i];
        now[++tot] = a[i];
        // cout << tot << endl;
        // for (int i = 1; i<= tot;i++){
        //     cout << now[i] << ' ';
        //     // cnt[k]++;
        // }
        // cout << endl;
        // cout << endl;
    }
    for (int i = 1; i<= tot;i++){
        // cout << now[i] << ' ';
        cnt[now[i]]++;
    }
    // cout << endl << "Nxe";
    }
int main() {
    freopen("card.in", "r", stdin);
    freopen("card.out", "w", stdout);
    cin >> n;
    
    cin >> m;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++) {
        solve(i);
    }
    for (int i = 1; i <= m; i++) {
        cout << cnt[i] <<' ';
    }
    return 0;
}
/*4 3
1 2 1 3*/