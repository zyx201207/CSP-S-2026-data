#include <bits/stdc++.h>
#define llong long long
#define N 2000006
using namespace std;

int n; llong d;
llong a[N];
int pre[N], nxt[N];
int dp1[N], dp2[N], dp3[N];
llong ans;

int _main(){
    cin >> n >> d;
    for(int i = 1; i <= n; ++i) cin >> a[i];
    // Initalize pointers
    pre[1] = 1;
    for(int i = 2; i <= n; ++i){
        pre[i] = pre[i-1];
        while(a[i]-a[pre[i]] > d) ++pre[i];
    }
    nxt[n] = n;
    for(int i = n-1; i >= 1; --i){
        nxt[i] = nxt[i+1];
        while(a[nxt[i]]-a[i] > d) --nxt[i];
    }
    // Work
    for(int i = 1; i <= n; ++i){
        if(pre[i] != i){
            int j = pre[i];
            // Pass 1s-border
            if(nxt[j] == i){
                dp1[i] += dp1[j];
            }
            // Convert 2s-border to 2s-tag
            int tag1 = dp3[j];
            ans += tag1;
            // Convert 2s-tag to 2s-border
            if(nxt[j] == i){
                dp3[i] += dp3[j];
            }
            // Convert 1s-border to 1m-border
            if(i != n && pre[i+1] == j && nxt[j] == i+1){
                dp2[i] += dp1[j];
            }
            // Convert 1m-border to 2s-tag
            int tag2 = dp2[j];
            ans += tag2;
            // Convert 2s-tag to 2s-border
            if(nxt[j+1] == i){
                dp3[i] += dp2[j];
            }
        }
        // Add 1s-border
        // First 1m or second 1s are special
        if(nxt[i] != i){
            ++dp1[nxt[i]];
            if(nxt[i] != i+1) ++dp2[nxt[i]-1];
        }
        // cerr << dp1[i] << " " << dp2[i] << " " << dp3[i] << "\n";
    }
    cout << ans << "\n";
    return 0;
}
void _init(){
    for(int i = 1; i <= n; ++i)
        pre[i] = nxt[i] = dp1[i] = dp2[i] = dp3[i] = 0;
    ans = 0;
    return;
}

int taskid, T;
int main(){
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin >> taskid >> T;
    while(T--) _init(), _main();
    return 0;
}
