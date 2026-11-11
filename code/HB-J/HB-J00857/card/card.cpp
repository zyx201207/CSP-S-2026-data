#include<bits/stdc++.h>
using namespace std;
int a[511111];
int ans[511111];
int sta[511111];
int stalen=0;
set<int>se;
int mp[311111];
int main (){
    freopen ("card.in","r",stdin);
    freopen ("card.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    for (int t = 1; t <= n; ++t){
        for (int i = t; i <= n; ++i){
            if (se.find(a[i]) != se.end()){
                int j = mp[a[i]];
                for (int k = j; k <= stalen; ++k){
                    if (se.find(sta[k]) != se.end()) se.erase(sta[k]);
                }
                stalen = j-1;
            }
            se.insert(a[i]);
            sta[++stalen] = a[i];
            mp[a[i]] = stalen;
        }
        for (int i = 1; i <= m; ++i){
            if (se.find(i) != se.end()) ans[i]++;
        }
        stalen = 0;
        se.clear();
    }

    for (int i = 1; i < m; ++i) cout << ans[i] << " ";
    cout << ans[m] << "\n";
    return 0;
}
