#include <iostream>
#include <vector>
#include <string>
using namespace std;
#define LL long long
int main()
{
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    LL n;
    cin >> n;
    vector<LL> num(n + 1);
    vector<char> word(n + 1);
    for (LL i = 0; i < n; ++i)
    {
        cin >> num[i] >> word[i];
    }
    LL all = 0;
    for (LL i = 0; i < n; ++i)
    {
        all += num[i];
    }
    LL counts, mid = all / 2;
    LL o = 0;
    while (mid > counts)
    {
        counts += num[o];
        ++o;
    }
    LL cha = mid - counts;
    LL ans = 0;
    LL x = 0;
    for (LL i = 0; i < num.size() / 2; ++i)
    {
        if (word[i] == word[num.size() - 1 - i])
        {
            x = num[i] - num[num.size() - 1 - i] - x;
            if (x < 0)
            {
                if (word[i] != word[num.size() - 2 - i])
                {
                    ans += x;
                }
            }
        }
    }
    cout << ans;

    return 0;
}
