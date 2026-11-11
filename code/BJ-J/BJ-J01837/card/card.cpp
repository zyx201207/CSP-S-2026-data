#include<bits/stdc++.h>
using namespace std;
int a[500005];
int ans[300005];
int la[300005];
int main() {
    freopen("card.in", "r", stdin);
    freopen("card.out", "w", stdout);
    int n, m;
    cin >> n >> m;
    bool flag = true;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        if(a[i] < a[i - 1]) flag = false;
        la[a[i]] = i;
    }
    if(flag) {
        for(int i = 1; i <= m; i++) {
            cout << la[i] << " ";
        }
        return 0;
    }
    for(int i = 1; i <= n; i++) {
        vector<int> b;
        for(int j = i; j <= n; j++) {
            for(int k = 0; k < b.size(); k++) {
                if(b[k] == a[j]) {
                    int s = b.size();
                    for(int l = k; l < s; l++) {
                        b.pop_back();
                    }
                    break;
                }
            }
            b.push_back(a[j]);
        }
        for(int j = 0; j < b.size(); j++) {
            ans[b[j]]++;
        }
    }
    for(int i = 1; i <= m; i++) cout << ans[i] << " ";
    cout << endl;
    return 0;
}