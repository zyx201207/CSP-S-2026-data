#include<bits/stdc++.h>
using namespace std;
int main() {
    freopen("card.in", "r", stdin);
    freopen("card.out", "w", stdout);
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n;
    int m;
    cin >> n >> m;
    int a[n];
    int b[n];
    int ans[m];
    for(int i = 0; i < m; ++i) {
        ans[i] = 0;
    }
    for(int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < n; ++j) {
            b[j] = a[j];
        }

        for(int j = i; j < n; ++j) {
            for(int k = i; k < j; ++k) {
                if(b[j] == b[k]) {
                    for(int l = k; l < j; ++l) {
                        b[l] = -1;
                    }
                }
            }
        }

        for(int j = i; j < n; ++j) {
            if(b[j] != -1) {
                ans[b[j]-1]++;
            }
        }
    }
    for(int i = 0; i < m; ++i) {
        cout << ans[i] << " ";
    }
    return 0;
}