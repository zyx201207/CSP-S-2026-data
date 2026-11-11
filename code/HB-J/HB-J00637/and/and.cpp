#include <bits/stdc++.h>
using namespace std;

vector<int> dp[100001];

int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","l",stdout);
    int n,m;
    cin >> n >> m;
    vector<int> nums;
    vector<int> dp;

    for (int i = 1;i <= n;i ++){
        int tmp;
        cin >> tmp;
        nums.push_back(tmp);
    }

    for (int i = 0;i <= m;i ++){
        dp.push_back(0);
    }

    int tmp = -919191;
    for (int i = 0;i < n;i ++){
        tmp = max(nums[i],tmp);
    }

    dp[1] = tmp;

    for (int i = m;i >= 0;i --){
        for (int j = 0;j < n;j ++){
            int tmp = -99999;
            tmp = max(dp[i - 1] & nums[j],tmp);
            dp[i] = tmp;

        }
    }
    int ans = -99999;
    cout << dp[m];
}
