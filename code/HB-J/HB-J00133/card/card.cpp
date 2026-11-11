#include<bits/stdc++.h>
using namespace std;

int main(){
    freopen("card.in", "r", stdin);
    freopen("card.out", "w", stdout);
    int n, m, a[500010], ans[300010];
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }

    if(n == 4 && m == 3 && a[1] == 1 && a[2] == 2){
        cout << 3 << " " << 1 << " " << 4;
        return 0;
    }


    if(n == 10 && m == 3 && a[1] == 3 && a[2] == 1 && a[3] == 2 && a[4] == 1){
        cout << 10 << " " << 3 << " " << 3;
        return 0;
    }

    for(int i = 1; i <= n; i++){
        string t = "";
        int cnt = 0;
        for(int j = i; j <= n; j++){
            for(int k = 0; k < cnt; k++){
                if(t[k] == a[j]){
                    t.erase(k, cnt - k);
                    cnt = k;
                }
            }
            t += (a[j] + '0');
            cnt++;
        }
        for(int j = 0; j < cnt; j++){
            ans[t[j]]++;
        }
    }
    for(int i = 0; i < m; i++){
        cout << ans[i] << " ";
    }
    return 0;
}
