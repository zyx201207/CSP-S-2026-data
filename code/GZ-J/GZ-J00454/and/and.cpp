//GZ-J00454 华东师范大学附属贵阳学校 蒋泽赟
#include <bits/stdc++.h>
using namespace std;

int n, m;
int nums[200005];
string num2[200005];

int find(int x)
{
    int l = 1, r = n, ans;
    while (l < r)
    {
        int mid = (l + r) >> 1;
        if (nums[mid] >= x)
        {
            ans = mid;
            l = mid + 1;
        }
        else
        {
            r = mid;
        }
    }
    return ans;
}

bool cmp(int x, int y) {return x > y;}

int main()
{
     freopen("and.in", "r", stdin);
     freopen("and.out", "w", stdout);
    cin >> n >> m;
    for (int i = 1; i <= n; ++i)
    {
        scanf("%d", &nums[i]);
    }
    sort(nums + 1, nums + n + 1, cmp);
    int x = log2(nums[1]);
    int ans = 0;
    for (int i = x; i >= 0; --i)
    {
        int y = find(ans + (1 << i));
        if (y >= m) ans += (1 << i);
    }
    cout << ans << endl;
    return 0;
}
