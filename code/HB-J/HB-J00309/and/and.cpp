#include <bits/stdc++.h>
using namespace std;
//对于每个数A，记录他的二进制值， 并且统计每位上所有的1的数量
unsigned long long a;
const int N = 2e5 + 5;
int n, k;
string b[N];

set<int> s[N];
int sum[32];
set<int> tmp;

void solve1()
{
    cin >> n >> k;
    for (int i = 1; i <= n; ++i)
    {
        cin >> a;
        string cnt = "";
        while (a)
        {
            cnt += (a % 2 == 0 ? '0' : '1');
            a /= 2;
        } //转二进制，从左往有看是从小到大
        // reverse(cnt.begin(), cnt.end());
        b[i] = cnt; // 存储对应二进制数
    }
    int maxn = -1;
    string ans = "";

    for (int i = 1; i <= n; ++i)
    {
        for (int j = 0; j < b[i].size(); ++j)
            if (b[i][j] == '1')
                sum[j]++, s[j].insert(i), tmp.insert(j), maxn = (sum[j] >= k ? max(maxn, j) : maxn); // 如果当前位置大于当前的位数且当前位置有>=k个数可以按位与得来， 那么进行判断位数是不是大于前面的位数
    }                                                                                                //第一轮开始寻找最大位数的值

    if (maxn == -1)
    {
        cout << 0;
        return;
    }

    // for (int i = 1; i <= n; ++i)
    //     cout << b[i] << ' ';
    // for (int j = 0; j <= 6; ++j)
    //     cout << sum[j] << ' ';
    while (maxn >= 0)
    {
        ans += '1';
        set<int> tmp2 = s[maxn];
        int tmp3 = maxn;

        for (auto ca : tmp)
            s[ca].clear(), sum[ca] = 0; //清除所有位数含1个数，为下一次循环做回溯
        tmp.clear();
        maxn = -1;

        for (auto i : tmp2) //遍历当前最高位所含有的可以按位与求解出的数
        {
            for (int j = 0; j < tmp3; ++j) // 遍历到当前最大位置以前
                if (b[i][j] == '1')
                    sum[j]++, s[j].insert(i), tmp.insert(j), maxn = (sum[j] >= k ? max(maxn, j) : maxn);
        }

        for (int i = tmp3 - 1; i > maxn; --i) // 在 (原maxn. 现maxn)区间内无法取到数则在此区间添加0
            ans += '0';                       //在maxn位置上需要添加1, maxn最小为-1，未能取时值为-1，所以i不会使程序RE
    }
    unsigned long long real_ans = 0, cj = 1;
    // cout << ans << '\n';
    reverse(ans.begin(), ans.end()); //从最高位到最低位，而还原是从低到高

    for (int i = 0; i < ans.size(); ++i, cj *= 2)
        real_ans += (ans[i] - '0') * cj;

    cout << real_ans;
}
int main()
{
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    solve1(); // 时间复杂度大约为O(186N)
    return 0;
}