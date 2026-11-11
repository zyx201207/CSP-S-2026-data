#include <bits/stdc++.h>
#define pii pair < int, int >
#define F first
#define S second
using namespace std;

typedef long long ll;

const int N = 2e5;

int n, m;

vector < int > num, tmp;

int ans;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);
    cin >> n >> m;
    for (int i = 1 ; i <= n ; i++)
    {
        int now;
        cin >> now;
        num.push_back(now);
    }
    for (int i = 30 ; i >= 0 ; i--)
    {
        int cnt = 0;
        for (int j : num)
        {
            if (j & (1 << i)) cnt++;
        }
        if (cnt >= m)
        {
            ans |= (1 << i);
            for (int j : num)
            {
                if (j & (1 << i)) tmp.push_back(j);
            }
            num = tmp;
            tmp.clear();
        }
    }
    cout << ans << '\n';
    return 0;
}
