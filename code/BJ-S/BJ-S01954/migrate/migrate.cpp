#include<bits/stdc++.h>
using namespace std;
#define my ios::sync_with_stdio(0)

long long c, t, tot, n, d, a[2000002], dist;
vector<int> flying[2000002];

bool check(long long u, long long v){
    for(auto to : flying[u]){
        if(to == v) return true;
    }
    return false;
}

void dfs(long long u, long long v){
    if(u > v) return;
    if(u == v){
        dist++;
        return;
    }
    for(auto to : flying[u]){
        dfs(to, v);
    }
    return;
}

int main(){
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    my;
    cin.tie(0);
    cout.tie(0);
    cin >> c >> t;
    while(t--){
        if(c <= 10){
            for(int i = 1;i <= n;i++) flying[i].clear();
            tot = 0;
            cin >> n >> d;
            for(int i = 1;i <= n;i++){
                cin >> a[i];
            }
            for(int i = 1;i <= n;i++){
                for(int j = i + 1;j <= n;j++){
                    if(abs(a[i] - a[j]) <= d){
                        flying[i].push_back(j);
                    }
                }
            }
            for(int u = 1;u <= n;u++){
                for(int v = u + 1;v <= n;v++){
                    if(check(u, v)) continue;
                    dist = 0;
                    dfs(u, v);
                    if(dist == 3){
                        tot++;
                    }
                }
            }
            cout << tot << "\n";
        }
        else{
            cout << 0 << endl;
        }
    }
    return 0;
}
