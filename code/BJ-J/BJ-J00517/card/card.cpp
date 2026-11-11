#include<bits/stdc++.h>
using namespace std;
int n, m, a[500005],ans[500005], fl1 = 1, fl2 = 1, fl3 = 1;
int main(){
    freopen("card.in", "r", stdin);
    freopen("card.out", "w", stdout);
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        if(a[i] < a[i - 1]) fl1 = 0;
        if(a[i] >= 3) fl3 = 0;

    }
    if(fl1){
        a[n + 1] = INT_MAX;
        for(int i = 2; i <= n + 1; i++){
            if(a[i] != a[i - 1]){
                cout << i - 1 << ' ';
            }
        }
        cout << endl;
    }
    else{
        for(int p = 1; p <= n; p++){
            int vis[n + 5], del[n + 5];
            for(int i = p; i <= n; i++){
                if(vis[a[i]]){
                    for(int j = i; j >= 1; j--){
                        if(a[i] == a[j]){
                            for(int k = j; k <= i; k++){
                                del[k] = 1;
                            }
                        }
                    }
                }
                vis[a[i]] = 1;
            }
            for(int i = 1; i <= m; i++){
                if(!del[i]) ans[i]++;
            }
        }
        for(int i = 1; i <= m; i++) cout << ans[i] << ' ';
    }
}
