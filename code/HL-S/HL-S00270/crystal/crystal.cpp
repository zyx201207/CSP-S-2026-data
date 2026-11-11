#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e5+10, M = 1e3+10;
int a[N] = {0}, b[M][M] = {0};
int n, m, sum = 0, cnt = 0;
signed main(){
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    cin >> n >> m;
    for(int i = 1; i<=n; i++){
        cin >> a[i];
    }
    sort(a, a+n+1);
    for(int i = 1; i<=n; i++){
        for(int j = 1; j<=n; j++){
            b[i][j] = 0;
        }
    }
    for(int i = 1; i<=n; i++){
        for(int j = i+1; j<=n; j++){
            b[i][j] = a[j]-a[i];
        }
    }
    int res = 0;
    for(int i = 1; i<=n; i++){
        for(int j = i+1; j<=n; j++){
            sum += b[i][j];
            cnt++;
            if(sum == m){
                res = max(res, cnt);
                break;
            }
            else if(sum >= m){
                break;
            }
        }
        sum = 0;
        cnt = 0;
    }
    cout << res;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
