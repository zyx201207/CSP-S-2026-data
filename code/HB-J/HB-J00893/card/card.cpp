#include <bits/stdc++.h>
using namespace std;
int n, m;
int main (){
    freopen("card.in", "r", stdin);
    freopen("card.out", "w", stdout);
    cin >> n >> m;
    int a[n + 5];
    int ans[m + 5];
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }
    for (int i = n; i > 0; i++){;
        int b[i] = {};
        int cnt = 0;
        for (int j = 0; j < i; j++){
            b[i] = a[i];
            for (int k = 0; k < i - 1; k++){
                if (b[i] == b[k]){
                    for (int l = 0; l < i; l++){
                        b[i] = 0;
                    }
                }
            }
        }
        for (int j = 0; j < b.size(); j++){
            ans[b[i]]++;
        }
    }
    for (int i = 1; i <= ans.size(); i++){
        cout << ans[i];
    }
    return 0;
}
