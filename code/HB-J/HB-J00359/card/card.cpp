#include <bits/stdc++.h>
using namespace std;
const int N = 3e5 + 10;
int n, m, vis[N];
vector <int> a;
void dfs(int l, int r){
    auto it = a.begin() + l;
    for (it = it; it < a.end();){
        auto iit = find(it+1, a.end(), *it);
        if (iit == a.end()){vis[*it]++; it++;}
        else it = iit;
    }
}
int main(){
    freopen("card.in", "r", stdin);
    freopen("card.out", "w", stdout);
    cin >> n >> m;
    for (int i = 0; i < n; i++){int x; cin >> x; a.push_back(x);}
    for (int i = 0; i < n; i++) dfs(i, n-1);
    for (int i = 1; i <= m; i++) cout << vis[i] << ' ';
    return 0;
}
