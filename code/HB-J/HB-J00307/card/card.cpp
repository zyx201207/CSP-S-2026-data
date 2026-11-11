#include <bits/stdc++.h>
using namespace std;
#define int long long
int n, m, ans[500005], a[500005];
signed main(){
    freopen("card.in", "r", stdin);
    freopen("card.out", "w", stdout);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++){
        string s = "";
        for (int j = i; j <= n; j++){
            s += a[j];
            string s2 = "";
            for (int k = 0; k < s.size(); k++){
                if (s[k] != a[j]) s2 += s[k];
                else{
                    s = s2 + s[k];
                    break;
                }
            }
        }
        for (int j = 0; j < s.size(); j++) ans[s[j]]++;
    }
    for (int i = 1; i <= m; i++) cout << ans[i] << " ";
    cout << endl;
    return 0;
}
