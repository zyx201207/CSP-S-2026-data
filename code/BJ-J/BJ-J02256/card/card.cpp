#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 10;
stack<int> stk;
int n, m, a[N], ans[N];
bool used[N];
void card(int x){
    if(used[x]){
        while(stk.top() != x) {
            used[stk.top()] = false;
            stk.pop();
        }
        return;
    }
    stk.push(x);
    used[x] = true;
}
int main(){
    freopen("card.in", "r", stdin);
    freopen("card.out", "w", stdout);
    cin >> n >> m;
    for(int i = 1; i <= n; i++) cin >> a[i];
    for(int i = 1; i <= n; i++){
        for(int j = i; j <= n; j++)
            card(a[j]);
        while(stk.size()){
            int x = stk.top(); stk.pop();
            used[x] = false;
            ans[x]++;
        }
    }
    for(int i = 1; i <= m; i++) cout << ans[i] << ' ';
    cout << '\n';
    return 0;
}