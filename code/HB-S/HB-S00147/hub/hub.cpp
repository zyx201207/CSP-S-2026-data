#include<bits/stdc++.h>
using namespace std;
const int N = 1e6+5;
int C, T;
int n, k;
int ans;
int v[N], vt[N];
vector<int>a[N];
int dc(int kk, int ss){
    if (v[kk]) return ss;
    vt[kk] = 1;
    int res = 0;
    for (auto to:a[kk]){
        if (vt[to]) continue;
        res = max(res, dc(to, ss+1));
    }
    vt[kk] = 0;
    return res+ss;
}
void dff(int kk, int s, int sk){
    //cout << kk << " " << s << " " << sk << '\n';
    if (sk >= 2 || s == k){
        int res = 0;
        for (int i = 1; i <= n; i++){
            res = max(dc(i, 0), res);
        }
        ans = min(ans, res);
        return ;
    }
    if (kk > n || v[kk]) return ;
    dff(kk+1, s, sk);
    queue<pair<int, int>>q;
    q.push({kk, s+1});
    vt[kk] = 1;
    while(!q.empty()){
        int x = q.front().first, ss = q.front().second;
        q.pop();
        if (ss > k) {
            v[x] = 0;
            continue;
        }
        v[x] = 1;
        dff(k+1, ss, sk+1);
        for (auto to:a[x]){
            if (v[to] || vt[to]) continue;
            vt[to] = 1;
            q.push({to, ss+1});
        }
        v[x] = 0;
    }
    memset(vt, 0, sizeof vt);
    return ;
}

int main(){
    freopen("hub.in", "r", stdin);
    freopen("hub.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> C >> T;
    while(T--){
        cin >> n >> k;
        ans = 1e7;
        for (int i = 1; i <= n; i++) {
            a[i].clear();
            v[i] = 0;
        }
        for (int i = 1; i < n; i+=1) {
            int x, y;
            cin >> x >> y;
            a[x].push_back(y);
            a[y].push_back(x);
        }
        dff(1, 0, 0);
        cout << ans << '\n';
    }

    return 0;
}
