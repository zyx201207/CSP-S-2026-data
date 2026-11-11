#include <iostream>
#include <algorithm>
#define N 200000
using namespace std;

int n,m,a[N],ans;
void dfs(int x,int andsum, int num) {
    if(num > m) return;
    if(x > n) {
        if(num == m)
            ans = max(ans, andsum);
        return;
    }
    dfs(x+1, (num?(a[x]&andsum):a[x]), num+1);
    dfs(x+1, andsum, num);
}
int main() {
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);
    cin >> n >> m;
    for(int i=1;i<=n;i++) {
        cin >> a[i];
    }
    if(n <= 23) {
        dfs(1, -1, 0);
        cout << ans;
    } else if(m == 1) {
        sort(a+1, a+n+1);
        cout << a[n];
    } else if(m == n) {
        ans = a[1];
        for(int i=2;i<=n;i++) ans &= a[i];
        cout  << ans;
    } else if(m == 2 && n <= 3000) {
        for(int i=1;i<n;i++) {
            for(int j=i+1;j<=n;j++) {
                ans = max(ans, a[i]&a[j]);
            }
        }
        cout << ans;
    } else if(m == 3 && n <= 240) {
        for(int i=1;i<n-1;i++) {
            for(int j=i+1;j<n;j++) {
                for(int k=j+1;k<=n;k++) {
                    ans = max(ans, a[i] & a[j] & a[k]);
                }
            }
        }
        cout << ans;
    } else if(m == n - 1) {
        for(int i=1;i<=n;i++) {
            int aans = 0b1111111111111111111111111111111;
            for(int j=1;j<=n;j++) {
                if(i != j) aans &= a[j];
            }
            ans = max(ans, aans);
        }
        cout << ans;
    } else {
        sort(a+1, a+n+1);
        cout << a[n-m+1];
    }
    return 0;
}
