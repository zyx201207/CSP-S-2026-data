#include <bits/stdc++.h>
using namespace std;
int n, m;
long long a[200005], ans, maxn;
int main()
{
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        maxn = max(maxn, a[i]);
    }
    if(m == 1){
        cout << maxn;
        return 0;
    }
    if(m == n){
        ans = a[1];
        for(int i = 2; i <= n; i++){
            ans = ans & a[i];
        }
        cout << ans;
        return 0;
    }
    if(m == 2){
        for(int i = 1; i <= n; i++){
            for(int j = i+1; j <= n; j++){
                ans = max(ans, a[i] & a[j]);
            }
        }
        cout << ans;
        return 0;
    }
    if(m == 3){
        for(int i = 1; i <= n; i++){
            for(int j = i+1; j <= n; j++){
                for(int k = j+1; k <= n; k++){
                    ans = max(ans, a[i] & a[j] & a[k]);
                }
            }
        }
        cout << ans;
        return 0;
    }
    if(m == 4){
        for(int i = 1; i <= n; i++){
            for(int j = i+1; j <= n; j++){
                for(int k = j+1; k <= n; k++){
                    for(int l = k+1; l <= n; l++){
                        ans = max(ans, a[i] & a[j] & a[k] & a[l]);
                    }
                }
            }
        }
        cout << ans;
        return 0;
    }
	return 0;
}
