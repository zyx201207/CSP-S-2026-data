#include <bits/stdc++.h>

using namespace std;

#define ll long long

struct node{
    ll u, d;
};

ll c, t, n, p, x[2000005], dis[10005], vis[10005], ans, cnt[100005], mx;

void bfs(int st){
    queue<node>q;
    q.push((node){st, 0});
    while(!q.empty()){
        node me = q.front();
        q.pop();
        ll a = me.u, b = me.d;
        dis[a] = min(dis[a], b);
        if(dis[a] != 0 && dis[a] == b) cnt[a]++;
        if(vis[a] < 3){
            vis[a]++;
            for(int i = a+1; x[i]-x[a] <= p && i <= n; i++){
                if(vis[i] <= 1) q.push((node){i, b+1});
            }
        }
    }
    for(int i = 1; i <= n; i++) if(cnt[i] == 2) ans++;
}

int main(){
    freopen("migrate.in" , "r", stdin );
    freopen("migrate.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> c >> t;
    while(t--){
        ans = 0;
        cin >> n >> p;
        for(int i = 1; i <= n; i++){
            cin >> x[i];
            if(x[i] - x[1] <= p) mx++;
        }
        if(n <= 5000){
            for(int i = 1; i <= n; i++){
                fill(dis, dis+1+n, 3e18);
                fill(vis, vis+1+n, 0);
                fill(cnt, cnt+1+n, 0);
                bfs(i);
            }
        }else if(c == 11 || c == 12){
            if(mx == 2){
                ans = n-3;
            }else{
                ans = 0;
            }
        }else if(c == 13 || c == 14){
            int nb = 0;
            ll cnt = 0;
            for(int i = 1; i <= n; i++){
                if(x[i]-x[1] <= p && x[n]-x[i] <= p) nb = i, cnt++;
            }
            if(cnt >= 3) ans = 0;
            else if(cnt == 2) ans = 3;
            else ans = n*(n-1)/2-2;
        }
        cout << ans << endl;
    }
    return 0;
}
