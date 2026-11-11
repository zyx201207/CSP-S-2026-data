#include <iostream>
#include <cmath>
#include <cstring>
#include <unordered_set>
using namespace std;

const int N = 2 * 1e5 + 1;
int nums[N], dp[N];
unordered_set<int> us;

int main() {
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);
    
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < n; ++i) cin >> nums[i];

    memset(dp, 0, sizeof(dp));
    dp[0] = pow(2, 30) - 1;
    int idx;
    for(int i = 1; i <= m; ++i) {
        for(int j = 0; j < n; ++j) {
            int cur = nums[j] & dp[i-1];
            if(cur > dp[i] && (us.find(j) == us.end())) {
                dp[i] = cur;
                idx = j;
            }
        }
        us.insert(idx);
    }
    
    cout << dp[m] << endl;
    return 0;
}
