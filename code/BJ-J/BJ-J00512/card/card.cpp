#include<bits/stdc++.h>
using namespace std;
int n, m;
int ans[300005];
int a[500005];
int main(){
    freopen("card.in", "r", stdin);
    freopen("card.out", "w", stdout);
    cin >> n >> m;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
    }
    for (int k = 1; k <= n; k++){
        vector<int> c1;
        bool c2[300005] = {};
        c1.push_back(0);
        for (int i = k; i <= n; i++){
            if (c2[a[i]] == 0){
                c1.push_back(a[i]);
                c2[a[i]] = 1;
            }else{
                while (c1.size() != 1 && c1[c1.size() - 1] != a[i]){
                    c2[c1[c1.size() - 1]] = 0;
                    c1.pop_back();
                }
            }
        }
        for (int i = 1; i < c1.size(); i++){
            ans[c1[i]]++;
        }
    }
    for (int i = 1; i <= m; i++){
        cout << ans[i] << " ";
    }
    return 0;
}
