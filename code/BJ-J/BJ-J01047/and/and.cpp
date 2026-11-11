#include<bits/stdc++.h>
using namespace std;
int a[200005], n, m, ans;
struct num{
    int x, y;
    bool operator <(const num & other) const{
        return x < other.x;
    }
    bool operator ==(const num & other) const{
        return x == other.x && y == other.y;
    }
};
set<num> s;
int main(){
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);
    cin >> n >> m;
    s.insert({(1 << 30) - 1, 0});
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        for(auto j : s){
            if(j.y < m) s.insert({j.x & a[i], j.y + 1});
        }
    }
    for(auto i : s){
        if(i.y == m) ans = max(ans, i.x);
    }
    cout << ans;
    return 0;
}
