#include <bits/stdc++.h>
using namespace std;
const int N = 2e6 + 5;
const int P = 305;
int c,t,n,ls[N],rs[N],cnt,flag;
long long x[N],d,res;
inline void dfs(int u,int v,int k){
    if (u > v) return;
    if (u == v){
        if (k < res) flag = 1,res = k;
        else if (k == res) ++flag;
        return;
    }
    for (int i = u + 1;i <= rs[u];++i) dfs(i,v,k + 1);
}
inline void solve(){
    cin >> n >> d;
    cnt = 0;
    for (int i = 1;i <= n;++i) cin >> x[i];
    for (int i = 1;i <= n;++i){
        ls[i] = rs[i] = i;
        int l = 1,r = i;
        while (l <= r){
            int mid = (l + r) >> 1;
            if (x[i] - x[mid] <= d) ls[i] = mid,r = mid - 1;
            else l = mid + 1;
        }
        l = i + 1,r = n;
        while (l <= r){
            int mid = (l + r) >> 1;
            if (x[mid] - x[i] <= d) rs[i] = mid,l = mid + 1;
            else r = mid - 1;
        }
    }
    if (n <= 300){
        for (int i = 1;i <= n;++i) for (int j = i + 1;j <= n;++j){
            flag = 0,res = 0x3f3f3f3f3f3f3f3f;
            dfs(i,j,0);
            if (flag == 2) ++cnt;
        }
        cout << cnt << "\n";
        return;
    }
    for (int i = 1;i <= n;++i){
        bool tag = false;
        int now = i,lnow = 0;
        for (int j = i + 1;j <= n;++j){
            if (now == rs[now]) break;
            while (rs[now] < j){
                lnow = now,now = rs[now];
                if (now == rs[now]) break;
            }
            if (now == i) continue;
            if (ls[j] < now - 1) break;
            if (ls[j] == now - 1){
                if (tag || max(i,ls[ls[now]]) != lnow) break;
                tag = true;
            }
            if (tag) ++cnt;
            while (j <= n && ls[++j] == now - 1) cnt += tag;
        }
    }
    cout << cnt << "\n";
}
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin >> c >> t;
    while (t--) solve();
    return 0;
}