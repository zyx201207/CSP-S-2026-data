#include<bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;

const int N = 5e5 + 1, M = 3e5 + 1;

bool A = 1;
int n, m;
int a[N];

namespace S1{
    int ans[M];
    bool vis[M];
    stack<int> cards;
    void Solve(){
        fill(ans, ans + 1 + n, 0);
        for(int i = 1; i <= n; i++){
            for(int j = i; j <= n; j++){
                int num = a[j];
                if(vis[num]){
                    while(cards.size() && cards.top() != num){
                        vis[cards.top()] = 0;
                        cards.pop();
                    }
                }else{
                    vis[num] = 1;
                    cards.push(num);
                }
            }
            while(!cards.empty()){
                ans[cards.top()]++;
                vis[cards.top()] = 0;
                cards.pop();
            }
        }
        for(int i = 1; i <= m; i++) cout << ans[i] << " ";
    }
}

namespace Sp1{
    int ans[M];
    void Solve(){
        for(int i = 1; i <= n; i++) ans[a[i]] = max(i, ans[a[i]]);
        for(int i = 1; i <= m; i++) cout << ans[i] << " ";
    }
}

int main(){
    ios::sync_with_stdio(0), cin.tie(0);
    freopen("card.in", "r", stdin);
    freopen("card.out", "w", stdout);
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        if(a[i] < a[i - 1]) A = 0;
    }
    if(A) Sp1::Solve();
    else S1::Solve();
    return 0;
}
