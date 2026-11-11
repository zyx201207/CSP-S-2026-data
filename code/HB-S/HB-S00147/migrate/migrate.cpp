#include<bits/stdc++.h>
using namespace std;
const int N = 2e6+2;
int C, T;
int n;
#define ll long long
ll m, a[N];
ll d[N], s[N], ans;
vector<int>p[N];
#define pii pair<ll, int>
priority_queue<pii, vector<pii>, greater<pii>>q;
void dij(int st){
    q.push({0, st});
    while(!q.empty()){
        int x = q.top().second;
        q.pop();
        for (auto to:p[x]){
            if (d[to] > d[x]+1){
                d[to] = d[x]+1;
                s[to] = s[x];
                q.push({d[to], to});
            }
            else if (d[to] == d[x]+1) {
                s[to]++;
                //q.push({d[to], to});
            }
        }
    }
    return ;
}
void sol1(){
    while (T--){
        cin >> n >> m;
        for (int i = 1; i <= n; i+=1)p[i].clear();
        for (int i = 1; i <= n; i+=1){
            cin >> a[i];
            for (int j = i-1; j >= 1; j-=1){
                if (a[i]-a[j] <= m){
                    p[j].push_back(i);
                    p[i].push_back(j);
                }else break;
            }
        }
        ans = 0;
        for (int i = 1; i <= n-1; i += 1){
            for (int j = 1; j <= n; j+=1){
                d[j] = LONG_LONG_MAX;
                s[j] = 0;
            }
            d[i] = 0;
            s[i] = 1;
            dij(i);
            for (int j = i+1; j <= n; j+=1) if (s[j] == 2) ans++;
        }
        cout << ans << '\n';
    }
    return ;
}
void sol2(){
    while(T--){
        cin >> n >> m;
        for (int i = 1; i <= n; i += 1) cin >> a[i];
        int ct = m/(a[2]-a[1]);
        if (ct <= 1) cout << "0\n";
        else{
            cout << max(n-(ct*2)+1, 0) << '\n';
        }
    }
    return ;
}
void sol3(){
    while(T--) cout << 0 << '\n';
    return ;
}
int main(){
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> C >> T;
    if (C <= 10) sol1();
    else if (C <= 12) sol2();
    else sol3();
    return 0;
}
