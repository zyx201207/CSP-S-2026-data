#include<bits/stdc++.h>
using namespace std;
#define int long long
#define il inline
#define rg register
#define vi std::vector<int>
#define pb push_back
#define us(n) (1LL << n)
#define L(i, a, b) for (rg int i = (a); i <= (b); i++)
#define R(i, a, b) for (rg int i = (a); i >= (b); i--)
#define rep(i, a) for (rg auto i : (a))
const int N = 5e5 + 5, M = 21, p = 1e9 + 7, inf = 8e18;
namespace xyx{
    int n, m, a[N];
    il void slv(){
        std::cin >> n >> m; L(i, 1, n) std::cin >> a[i]; int l = 1, cost = 0, ans = 1;
        sort(a + 1, a + n + 1);
        L(r, 2, n){
            int len = r - l, d = a[r] - a[r - 1]; cost += len * d;
            while(l <= r && cost > m) cost -= a[r] - a[l], l++;
            ans = std::max(ans, r - l + 1);
        }
        std::cout << ans << "\n";
    }
} signed main(){
    freopen("crystal.in", "r", stdin); freopen("crystal.out", "w", stdout);
    ios::sync_with_stdio(false); cin.tie(0), cout.tie(0);
    return xyx::slv(), 0;
}
/*
g++ crystal.cpp -o crystal.exe -std=c++14 -O2 -Wall -Wextra -Wshadow "-Wl,--stack=512000000";if($?){./crystal}
*/