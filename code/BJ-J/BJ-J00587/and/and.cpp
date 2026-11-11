#include<iostream>
#include<stdio.h>
#include<algorithm>
using namespace std;

int n, m;
long long ans;
long long a[100010];

int main(){
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);

    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }

    if(n == m){
        ans = a[1];
        for(int i = 1; i <= n; i++){
            ans &= a[i];
        }
        cout << ans << endl;
        return 0;
    }
    if(m == 1){
        sort(a + 1, a + n + 1);
        cout << a[n] << endl;
        return 0;
    }
    if(m == 2){
        for(int i = 1; i <= n; i++){
            for(int j = i+1; j <= n; j++){
                ans = max(ans, a[i] & a[j]);
            }
        }
        cout << ans << endl;
        return 0;
    }
    if(m == n - 1){
        long long t;
        for(int i = 1; i <= n; i++){
            int x = 1;
            if(x == 1){
                x++;
            }
            t = a[x];

            for(int j = 1; j <= n; j++){
                if(j == i){
                    continue;
                }
                t &= a[j];
            }

            ans = max(ans, t);
        }

        cout << ans << endl;
    }
}
