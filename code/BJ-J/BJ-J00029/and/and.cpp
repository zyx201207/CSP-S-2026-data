#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
int n, m;
long long a[N];
bool b[N];
map<long long, int> mp;
long long ma = LONG_LONG_MIN;
int an(long long x, long long y){
    string q;
    while(x != 0){
            char c = (x % 2) + '0';
        q.push_back(c);
        x /= 2;
    }
    string p;
    while(y != 0){
        char c = (y % 2) + '0';
        p.push_back(c);
        y /= 2;
    }
    int cnt = 0;
    string ans;
    for(int i = max(q.size(), p.size()) - 1;i >= 0; i--){
        int o = 0, z = 0;
        if(i <= q.size() - 1) o = q[i] - '0';
        if(i <= p.size() - 1) z = p[i] - '0';
        if(o == 1 && z == 1){
            cnt++;
            ans.push_back(1);
        }
        else{
            ans.push_back(0);
        }

    }
    int g = 0;
    if(cnt > 1){
        for(int i = 0;i < ans.size(); i++){
            int d = ans[i] - '0';
            g += d * pow(2, i);
        }
    }
    return g;
}
void dfs(int cnt, long long ans){
    if(cnt > m){
        ma = max(ma, ans);
        return ;
    }
    for(int i = 1;i <= n; i++){
        if(mp[a[i]] == 0) continue;
        mp[a[i]]--;
        int u = an(ans, a[i]);
        dfs(cnt + 1, ans );
        mp[a[i]]++;
    }
}
int main(){
    freopen("and.in", "r", stdin);
    freopen("ans.out", "w", stdout);
    cin >> n >> m;
    for(int i = 1;i <= n; i++){
        cin >> a[i];
        if(mp.count(a[i]) == 0){
            mp[a[i]] = 1;
        }
        else{
            mp[a[i]]++;
        }
    }
    dfs(1, 0);
    cout << ma;
    return 0;
}
