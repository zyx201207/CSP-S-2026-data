#include<bits/stdc++.h>
using namespace std;
int n, m, a[200005], cnt, ans = -1;

int main()
{
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    if(m == 1){
        int mmax =  -1;
        for(int i = 1; i <= n; i++){
            if(a[i] > mmax){
                mmax = a[i];
            }
        }
        cout << mmax;
        return 0;
    }
    if(m == n){
        int ans = a[1];
        for(int i = 2; i <= n; i++){
            ans  = ans & a[i];
        }
        cout << ans;
        return 0;
    }
    if(m == 2){
        for(int i = 1; i <= n; i++){
            for(int j = i + 1; j <= n; j++){
                ans = max(ans, a[i] & a[j]);
            }
        }
        cout << ans;
    }
    if(m == n - 1){
        int f = 1;
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                if(j != i){
                    if(f == 1){
                        cnt = a[j];
                        f = 0;
                    }
                    else{
                        cnt = cnt & a[j];
                    }
                }
            }
            ans = max(ans, cnt);
            f = 1;
        }
        cout << ans;
        return 0;
    }
    return 0;
}

