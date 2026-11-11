#include <bits/stdc++.h>
using namespace std;

int main(){
    // #define int long long int
    freopen("and.in", "r",stdin);
    freopen("and.out", "w",stdout);

    int n, m;
    cin >> n >> m;
    int arr[200001];
    int dp[2][20001];
    for(int i = 1; i <= n; i++){
        cin >> arr[i];
        dp[0][i] = INT32_MAX;
        dp[1][i] = INT32_MAX;
    }

    dp[0][0] = INT32_MAX;
    dp[1][0] = INT32_MAX;

    int *a = dp[0], *b = dp[1];
    for(int i = 1; i <= m; i++){
        a[i] = b[i-1]&arr[i];

        for(int j = i+1; j <= n; j++){
            a[j] = max( a[j-1], b[j-1]&arr[j] );
            
            //cout << a[j] << ' ';
        }
        //cout << endl;
        swap(a, b);
    }

    cout << b[n] << endl;
    return 0;
}