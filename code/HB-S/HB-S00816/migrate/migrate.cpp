#include<bits/stdc++.h>
using namespace std;
long long x[211111];
long long vis[211111];
vector<long long>f[211111];
long long n, d;
long long check(long long s, long long h){
    //cout << s << " " << h << ": ";
    fill (vis, vis+n+1, 0);
    queue<long long>que;
    long long sum = 0;
    que.push(s);
    while (!que.empty()){
        long long u = que.front(); que.pop();
        //cout << u << " ";//
        for (long long i = 0; i < f[u].size(); ++i){
            long long v = f[u][i];
            if (v != h){
                if (v > h || vis[v]) continue;
            }else{
                if (sum == 0){
                    sum++;
                    vis[h] = vis[u]+1;
                }else{
                    if (sum >= 2) return 0;
                    if (vis[h] == vis[u]+1) sum++;
                }
            }
            que.push(v);
            vis[v] = vis[u]+1;
        }
    }
    //cout << "\n";//
    if (sum == 2) return 1;
    return 0;
}
int main (){
    freopen ("migrate.in", "r", stdin);
    freopen ("migrate.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    long long c, t, ans;
    cin >> c >> t;
    while (t--){
        cin >> n >> d;
        for (long long i = 1; i <= n; ++i) while (f[i].size()) f[i].pop_back();
        long long minx;
        for (long long i = 1; i <= n; ++i) cin >> x[i], minx = min (minx, x[i]);
        if (minx < 0){
            minx = 0-minx;
            for (long long i = 1; i <= n; ++i) x[i] += minx;
        }
        for (long long i = 1; i < n; ++i){
            for (long long j = i+1; j <= n; ++j) if (x[j]-x[i]<=d){
                f[i].push_back(j);
            }
        }
        ans = 0;
        for (long long i = 1; i < n; ++i){
            for (long long j = i+1; j <= n; ++j){
                if (check(i, j)) ans++;//, cout << "  " << i << " " << j << "\n";
            }
        }
        cout << ans << "\n";
    }

    return 0;
}
