#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll c, t;
ll n, d;
ll x[2000005];
ll ans[2000005], ans2[2000005];
void dfs(ll now, ll now_place) {
    queue<ll> now_pla;
    queue<ll> now_use;
    queue<ll> now_inpla;
    //queue<ll> now_road;
    now_pla.push(now);
    now_use.push(0);
    now_inpla.push(now_place);
    //now_road.push(0);
    while(!now_pla.empty()) {
        ll pla = now_pla.front();
        ll use = now_use.front();
        ll inpla = now_inpla.front();
        //ll road = now_road.front();
        now_pla.pop();
        now_use.pop();
        now_inpla.pop();
        //now_road.pop();
        if(use == ans2[inpla]) {
            ans[inpla]++;
        }
        if(use < ans2[inpla]) {
            ans[inpla] = 1;
            ans2[inpla] = use;
        }
        for(int i = inpla + 1;i <= n;i++) {
            if(x[i] - x[inpla] <= d) {
                now_pla.push(x[i]);
                now_use.push(use + 1);
                now_inpla.push(i);
                //now_road.push(road + x[i] - x[inpla]);
            }
        }
    }
    return;
}
int main() {
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    cin >> c >> t;
    while(t--) {
        cin >> n >> d;
        for(ll i = 1;i <= n;i++) {
            cin >> x[i];
            ans[i] = 0;
            ans2[i] = 1000000000000000000;
        }
        ll cnt = 0;
        for(ll i = 1;i <= n;i++) {
            dfs(x[i], i);
            for(ll j = 1;j <= n;j++) {
                if(ans[j] == 2) {
                    cnt++;
                    //cout << j << endl;
                }
                ans[j] = 0;
                ans2[j] = 1000000000000000000;
            }
        }
        cout << cnt << endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
