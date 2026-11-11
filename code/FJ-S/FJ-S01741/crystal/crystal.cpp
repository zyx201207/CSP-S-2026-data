//点名泉州七中江南校区，装了 VS，好评
#include<bits/stdc++.h>
#define LL long long
using namespace std;
inline LL read(){
    LL x = 0, ff = 1;
    char c = getchar();
    while(!isdigit(c) && c != '-') c = getchar();
    if(c == '-') c = getchar(), ff = -1;
    while(isdigit(c)) x = x * 10 + c - '0', c = getchar();
    return x * ff;
}
const int N = 5.1e5;
int n;
LL m, a[N], sum[N];
int main(){
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    int casecnt = 1;
    while(casecnt --){
        n = read(), m = read();
        int ans = 1;
        for(int i = 1; i <= n; ++i)
            a[i] = read();
        sort(a + 1, a + n + 1);
        // for(int i = 1; i <= n; ++i)
        //     cout << a[i] << ' ';
        // puts("");
        for(int i = 1; i <= n; ++i){
            sum[i] = sum[i - 1] + a[i];
            int l = 1, r = i, mid;
            while(l <= r){
                mid = (l + r) >> 1;
                if(a[i] * (i - mid + 1ll) - (sum[i] - sum[mid - 1]) <= m)
                    ans = max(ans, i - mid + 1), r = mid - 1;
                else
                    l = mid + 1;
            }
            // cout << i << ' ' << r + 1 << '\n';
        }
        cout << ans << '\n';
    }
    return 0;
}
/*
g++ crystal.cpp -o crystal.exe -O2
./checker
*/