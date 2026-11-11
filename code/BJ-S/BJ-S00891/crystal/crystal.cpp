#include <bits/stdc++.h>

using i64 = long long;

const int MAXN = 5e5 + 5;

int n;
i64 m;
i64 a[MAXN], pre[MAXN];

i64 solve(int idx){
    int l = 1, r = idx - 1;
    int ret = idx;
    while(r >= l){
        i64 mid = (l + r) / 2;
        if(m >= (idx - mid) * a[idx] - (pre[idx - 1] - pre[mid - 1])){
            ret = mid;
            r = mid - 1;
        }else{
            l = mid + 1;
        }
    }
    //std::cout << idx << ' ' << ret << '\n';
    return (idx - ret + 1);
}

int main(){
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    std::cin >> n >> m;
    for(int i = 1; i <= n; ++i){
        std::cin >> a[i];
    }

    std::sort(a + 1, a + 1 + n);
    for(int i = 1; i <= n; ++i){
        pre[i] = pre[i - 1] + a[i];
    }

    i64 ans = 0;
    for(int i = 1; i <= n; ++i){
        ans = std::max(ans, solve(i));
    }

    std::cout << ans;
    return 0;
}