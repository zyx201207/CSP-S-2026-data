#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

const int mx = 5.1e5;
long long n, m;
long long ar[mx], pre[mx];

bool ck(long long s){
    deque <int> q;

    for(int i = 1; i <= n; ++i){
        while(!q.empty() && ar[q.back()] <= ar[i]) q.pop_back();
        while(!q.empty() && q.back() <= i - s) q.pop_front();
        q.push_back(i);

        long long mx = ar[q.front()];
        long long nt = mx * s - (pre[i] - pre[max(1ll * 0, i - s)]);
        if(i >= s && nt <= m) return true;

    }
    return false;
}

int main(){
    ios :: sync_with_stdio(false);
    cin.tie(nullptr);

    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);

    cin >> n >> m;
    for(int i = 1; i <= n; ++i) cin >> ar[i];
    sort(ar + 1, ar + 1 + n);
    for(int i = 1; i <= n; ++i) pre[i] = pre[i - 1] + ar[i];

    long long l = 0, r = n, ans = 0;
    while(l <= r){
        long long mid = (l + r) >> 1;
        if(ck(mid)) ans = mid, l = mid + 1;
        else r = mid - 1;
    }

    cout << ans;
}
