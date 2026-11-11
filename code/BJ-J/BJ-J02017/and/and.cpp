#include <bits/stdc++.h>
#define int long long
using namespace std;
int a[200010];
signed main(){
    freopen("and.in" , "r" , stdin);
    freopen("and.out" , "w" , stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int n , m;
    cin >> n >> m;
    for(int i = 1;i <= n;i++){
        cin >> a[i];
    }
    if(m == 1){
        sort(a + 1 , a + n + 1);
        cout << a[n];
    }
    else if(m == n){
        int ans = a[1];
        for(int i = 2;i <= n;i++){
                ans &= a[i];
        }
        cout << ans;
    }
    else if(m == 2){
        int ans = 0;
        for(int i = 1;i <= n;i++){
            for(int j = i + 1;j <= n;j++){
                ans = max(ans , a[i] & a[j]);
            }
        }
        cout << ans;
    }
    else if(n <= 20){
        int ans = 0;
        int x , y , maxn = 0;
        for(int i = 2;i <= m;i++){
            maxn = 0 , y = 0;
            if(i == 2){
                for(int j = 1;j <= n;j++){
                    for(int k = j + 1;k <= n;k++){
                        if(a[j] & a[k] >= maxn){
                            maxn = a[j] & a[k];
                            x = j , y = k;
                        }
                    }
                    a[x] = maxn;
                    a[y] = 0;
                }
            }
            else{
                for(int j = 1;j <= n;j++){
                    if(j == x) continue;
                    if(a[x] & a[j] >= maxn){
                        maxn = a[x] & a[j];
                        y = j;
                    }
                }
                a[x] = maxn;
                a[y] = 0;
            }
        }
        cout << a[x];
    }
    else{
        bool flag = 0;
        for(int i = 1;i <= n;i++){
            if(a[i] != i - 1){
                flag = 1;
                break;
            }
        }
        bool ff = 0;
        for(int i = 1;i <= n;i++){
            if(a[i] >= 4){
                ff = 1;
            }
        }
        if(flag){
            sort(a + 1 , a + n + 1);
            int x = n , ans = a[n];
            for(int i = 2;i <= m;i++){
                ans &= a[x - 1];
                x--;
            }
            cout << ans;
        }
        else if(!flag && !ff){
            sort(a + 1 , a + n + 1);
            int x = n , ans = a[n];
            for(int i = 2;i <= m;i++){
                ans &= a[x / 2];
                x /= 2;
            }
            cout << ans;
        }
        else if(ff){
            sort(a + 1 , a + n + 1);
            int ans = a[n] , x = 0 , f = 0;
            for(int i = n - 1;i >= 1;i--){
                if(x < m && a[i] != a[i + 1]){
                    f = 1;  
                    int cnt = 0;
                    for(int i = 1;i <= n;i++){
                        if(a[i] == '1' || a[i] == '3'){
                            cnt++;
                        }
                    }
                    if(cnt >= m && n - cnt >= m){
                        cout << 2;
                    }
                    else if(cnt >= m){
                        cout << 1;
                    }
                    else cout << 2;
                }
                x++;
                ans &= a[i];
            }
            if(f == 0){
                 cout << ans;
            }
        }
    }
    return 0;
}