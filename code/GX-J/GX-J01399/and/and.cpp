#include <iostream>
#include <vector>
using namespace std;
int main(){
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);
    int n, m;
    cin >> n >> m;
    vector<int> a(n, 0);
    for(int i = 0;i < n;i++){
        cin >> a[i];
    }vector<int> dp(n, 0);
    dp[0] = a[0];
    for(int i = 0;i < n;i++){
        int cnt = 0;
        for(int j = 1;j < m;j++){
            dp[i] = max((dp[i - 1] & a[i]), (a[i - 1] & a[i]));
        }
    }cout << dp[n-1] << "\n";
    return 0;
}
