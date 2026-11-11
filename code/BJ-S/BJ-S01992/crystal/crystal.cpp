#include <bits/stdc++.h>
#define int long long
using namespace std;
int a[500010] , sa[500010];
signed main(){
    freopen("crystal.in" , "r" , stdin);
    freopen("crystal.out" , "w" , stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int n , m;
    cin >> n >> m;
    for(int i = 1;i <= n;i++){
        cin >> a[i];
    }
    sort(a + 1 , a + n + 1);
    for(int i = 1;i <= n;i++){
        sa[i] = sa[i - 1] + a[i];
    }
    int maxn = 0;
    if(n <= 5000){
        for(int i = n;i >= 1;i--){
            int x = a[i] * i - sa[i];
            int y = 0;
            if(x <= m){
                if(i > maxn){
                cout << i << endl;
                    return 0; 
                }
                else{
                    cout << maxn << endl;
                    return 0;
                }
            }
            else{
                for(int j = i;j >= 1;j++){
                    y += a[i] - a[j];
                    if(y > m){
                        maxn = max(maxn , i - j);
                        break;
                    }
                }
            }
        }
    }
    else{
        for(int i = n;i >= 1;i--){
            int x = a[i] * i - sa[i];
            int y = 0;
            if(x <= m){
                if(i > maxn){
                cout << i << endl;
                    return 0; 
                }
                else{
                    cout << maxn << endl;
                    return 0;
                }
            }
        }
    }
    return 0;
}