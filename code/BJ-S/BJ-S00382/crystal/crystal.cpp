#include "bits/stdc++.h"
using namespace std;

int n, m;
int a[5000005];
int maxq = 0;

bool check(int x) {

    //printf("Debug: Exec Function check(%d)\n", x);
    int sum = 0;
    for(int i = 1; i < x; i++) {
        sum += a[x] - a[i];
    }
    //printf("Debug: Head:%d, Sub:%d\n", x, sum);

    for(int i = x + 1; i <= n; i++) {
        if(sum <= m) return true;
        sum -= (a[i - 1] - a[i - x]) + x*a[i - 1];
        sum += x*a[i];
        //printf("Debug: Head:%d, Sub:%d\n", i, sum);
    }

    return false;
}


int main() {


    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> m;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    sort(a + 1, a + n + 1);

    int l = 0, r = n, res = 0;
    while(l < r) {
        int mid = (l + r + 1) >> 1;

        if(check(mid) == 0) {
            r = mid - 1;
        }
        else {
            l = mid;
            res = max(res, mid);
            //printf("Debug: Done, res:%d\n", res);
        }
    }

    cout << res;

    return 0;
}
