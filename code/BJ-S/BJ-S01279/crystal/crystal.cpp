#include <iostream>
#include <iomanip>
#include <algorithm>
#include <cstring>
#include <vector>
typedef unsigned char uchar;
typedef unsigned int uint;
typedef long long longlong;
typedef unsigned long long ulonglong;
typedef long double ldouble;
#define int longlong
#define uint ulonglong
#define double ldouble
using namespace std;

const int N = 5e5 + 5;
int n, m;
int a[N], s[N];

inline bool chk(int x, int y){
    return (y - x + 1) * a[y] - (s[y] - s[x - 1]) <= m;
}

signed main(){
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
    }
    sort(a + 1, a + n + 1);
    for (int i = 1; i <= n; i++){
        s[i] = s[i - 1] + a[i];
    }
    int ans = 0;
    for (int i = 1; i <= n; i++){
        int l = 1, r = i;
        while (l < r){
            int mid = (l + r) >> 1;
            if (chk(mid, i)){
                r = mid;
            }
            else{
                l = mid + 1;
            }
        }
        ans = max(ans, i - l + 1);
    }
    cout << ans;
    return 0;
}