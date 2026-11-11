#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    freopen("card.in", "r", stdin);
    freopen("card.out", "w", stdout);
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    vector<int> jump(n, -1);
    vector<int> lst(m + 1, -1);
    for(int i = n - 1; i >= 0; i--)
    {
        if(lst[a[i]] == -1)
        {
            lst[a[i]] = i;
        }
        else
        {
            jump[i] = lst[a[i]];
        }
    }
    vector<long long> ans(n, 1);
    for(int i = 0; i < n; i++)
    {
        if(jump[i] != -1)
        {
            ans[jump[i]] += ans[i];
        }
        else
        {
            if(i < n - 1)
            {
                ans[i + 1] += ans[i];
            }
        }
    }
    for(int i = 1; i <= m; i++)
    {
        cout << ans[lst[i]];
        if(i != m) cout << ' ';
    }
    cout << endl;
    return 0;
}
