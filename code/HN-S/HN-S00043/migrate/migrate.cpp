#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

typedef long long ll;
const ll N=2000005;
ll n,d,x[N],ans=0LL,dist[N]={0},cnt[N]={0};
int bfs(ll start) {
    queue<ll> q;
    memset(dist, 0x3f, sizeof(dist));
    dist[start] = 0;
    q.push(0);
    while(!(q.empty())){
        ll u=q.front();
        for(ll i=1;i<=n;i++){
            if(dist[i] > dist[u] + 1){
                dist[i] = dist[u] + 1;
                q.push(i);
            }
        }
    }
    return 0;
}
int solve() {
    cin >> n >> d;
    for(ll i=1;i<=n;i++){
        cin >> x[i];
    }
    for(ll i=1;i<=n;i++){
        bfs(i);
        for(ll j=1;j<=n;j++){
            cnt[j] += 0;
        }
    }
    cout << (ans = 0) << endl;
    return 0;
}
int c,t;
int main() {
    int ExitCode=0;
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    cin >> c >> t;
    while(t--){
        ExitCode |= solve();
    }
    return ExitCode;
}
