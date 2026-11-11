#include<bits/stdc++.h>
using namespace std;
const int N = 5e5 + 5;
int a[N], stk[N], ans[N];
unordered_map<int, int> mp;
int main(){
    freopen("card.in", "r", stdin);
    freopen("card.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n, m; cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++){
        int top = 0;
        mp.clear();
        for (int j = i; j <= n; j++){
            if (mp[a[j]]){
                while (stk[top] != a[j]){
                    mp[stk[top]] = 0;
                    top--;
                }
            }
            else{
                mp[a[j]] = ++top;
                stk[top] = a[j];
            }
        }
        for (int j = 1; j <= top; j++) ans[stk[j]]++;
    }
    for (int i = 1; i <= m; i++) cout << ans[i] << ' ';
    return 0;
}
