#include<bits/stdc++.h>
using namespace std;
int a[500005], sta[500005], idx[500005], cnt[500005], n, m, p;
int main(){
    freopen("card.in", "r", stdin);
    freopen("card.out", "w", stdout);
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    for(int t = 1; t <= n; t++){
        memset(idx, 0, sizeof idx);
        p = 0;
        for(int i = t; i <= n; i++){
            if(idx[a[i]]){
                for(int j = idx[a[i]] + 1; j <= p; j++){
                    idx[sta[j]] = 0;
                }
                p = idx[a[i]];
            }else{
                sta[++p] = a[i];
                idx[a[i]] = p;
            }
        }
        for(int i = 1; i <= p; i++){
            cnt[sta[i]]++;
        }
    }
    for(int i = 1; i <= m; i++){
        cout << cnt[i] << ' ';
    }
    return 0;
}