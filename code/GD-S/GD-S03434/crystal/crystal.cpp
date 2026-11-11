#include <bits/stdc++.h>
using namespace std;
#define int long long
int nums[500005];
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }
    sort(nums, nums + n);
    int maxx = INT_MIN;
    int sum = 0;
    int j = n - 1;
    for (int i = n - 1; i >= 1; i--)
    {
        int thi = nums[i]; // thi -> 双指针开始的位置（从后往前）
        // cout << j << ' ';
        for (j--; (j >= 0) && ((sum + 1 * (nums[i] - nums[j])) <= m); --j)
        {
            sum += nums[i] - nums[j]; // 加差
        }
        j++;
        // if (j < 0)
        //     break;
        // cout << j << ' ' << nums[j] << ' ' << i << ' ' << nums[i] << ' ' << sum << ' ' << i - j << endl;
        maxx = max(maxx, i - j);
        // if (i == n - 1)
        // {
        //     i--;
        // }
        // else
        // if (i == 1)
        // {
        //     break;
        // }
        // else
        {
            // cout << ((nums[i] - nums[i - 1])) << ' ' << (i - j) << endl
            //      << endl;
            sum -= ((nums[i] - nums[i - 1]) * (i - j));
        }
    }
    cout << maxx + 1;
}
