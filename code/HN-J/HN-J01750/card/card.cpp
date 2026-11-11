#include<bits/stdc++.h>

using namespace std;
using ll = long long;

const int N = 5e5 + 10;

int n, m, a[N], vis[N], ans[N];
stack<int> stk;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    freopen("card.in", "r", stdin);
    freopen("card.out", "w", stdout);
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    for(int i = 1; i <= n; i++){
        fill(vis + 1, vis + m + 1, 0);
        while(!stk.empty()){
            stk.pop();
        }
        for(int j = i; j <= n; j++){
            if(vis[a[j]]){
                while(1){
                    if(stk.top() == a[j]){
                        break;
                    }
                    vis[stk.top()] = 0;
                    stk.pop();
                }
                //stk.pop();
            } else{
                stk.push(a[j]);
                vis[a[j]] = 1;
            }
            //for(int i = 1; i <= m; i++){
            //if(vis[i]) cout << i << ' ';
            //}
            //cout << '\n';
        }
        for(int i = 1; i <= m; i++){
            ans[i] += vis[i];
            //if(vis[i]) cout << i << ' ';
        }
        //cout << '\n';
    }
    for(int i = 1; i <= m; i++){
        cout << ans[i] << ' ';
    }
    return 0;
}
