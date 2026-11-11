#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 500;
int c, T, n, d, x[N], dis[N], cnt[N];
queue<int> q;
int check(int pos){
    for(int i = 1; i <= n; i++) dis[i] = 114514, cnt[i] = 0;
    cnt[pos] = 1, dis[pos] = 0;
    q.push(pos);
    while(q.size()){
        int fr = q.front(); q.pop();
        for(int j = fr + 1; x[j] - x[fr] <= d && j <= n; j++){
            if(dis[j] > dis[fr] + 1) dis[j] = dis[fr] + 1, cnt[j] = cnt[fr], q.push(j);
            else if(dis[j] == dis[fr] + 1) cnt[j] += cnt[fr];
        }
    }
    int tmp = 0;
    for(int i = pos + 1; i <= n; i++) if(cnt[i] == 2) tmp++;
    return tmp;
}
void work(){
    cin >> n >> d;
    int ans = 0;
    for(int i = 1; i <= n; i++) cin >> x[i];
    for(int i = 1; i <= n; i++) ans += check(i);
    cout << ans << '\n';
}
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    cin >> c >> T;
    for(int i = 1; i <= T; i++) work();
    cout << flush;
}
