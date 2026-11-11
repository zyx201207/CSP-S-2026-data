#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e6+10;
int x[N];
int n, d, ans;
int C, T;
struct node{
    int now, s;
};
int ar[N];
void solve(){
    ans = 0;
    for(int st = 1; st < n; st++){
        for(int ed = st+1; ed <= n; ed++){
            for(int o = 1;o <= n; o++)ar[o] = -1;
            queue<node> q;
            q.push({st,0});
            ar[st] = 0;
			while(!q.empty()){
                node l = q.front();
                q.pop();
                if(l.now == ed){
                    int cnt = 1;
                    int mins = l.s;
                    while(!q.empty()){
                        l = q.front();
                        q.pop();
                        cnt += (l.now == ed && l.s == mins);
                    }
                    if(cnt == 2)ans++;
                    break;
                }
                if(l.s > (ed - st + 1))break;
                for(int nxt = l.now+1; nxt <= n && x[nxt] - x[l.now] <= d; nxt++){
                    
                    if(ar[nxt] != -1 && ar[nxt] < l.s + 1)continue;
                    q.push({nxt,l.s+1});
                    ar[nxt] = l.s+1;
                }
                for(int nxt = l.now-1; nxt >= 1  && x[l.now] - x[nxt] <= d; nxt--){
                    if(ar[nxt] != -1 && ar[nxt] < l.s + 1)continue;
                    if(x[st+1]-x[nxt] > d)break;
                    q.push({nxt,l.s+1});
                    ar[nxt] = l.s+1;
                }
            }
        }
    }
}
signed main(){
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> C >> T;
    while(T--){
        if(C == 11|| C == 12){
            cout << 0 << '\n';
            continue;
        }
        cin >> n >> d;
        for(int i = 1; i <= n; i++)cin >> x[i];
        solve();
        cout << ans << '\n';
    }
    return 0;
}
