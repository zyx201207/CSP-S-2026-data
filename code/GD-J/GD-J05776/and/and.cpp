#include <bits/stdc++.h>
using namespace std;
const int N = 200001;
int n, m, mxres;
bool vis[N];
vector<int> cho;
int a[N];
void dfs(int step)
{
    if (step == m + 1)
    {
        int res = cho[0];
        for (int i = 1; i < cho.size(); i++)
            res &= cho[i];
        mxres = max(res, mxres);
    }
    for (int i = 1; i <= n; i++)
    {
        if (vis[i])
            continue;
        cho.push_back(a[i]);
        vis[i] = 1;
        dfs(step + 1);
        vis[i] = 0;
        cho.pop_back();
    }
}
int main()
{
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    if (m == 1)
    {
        int mx = 0;
        for (int i = 1; i <= n; i++)
            mx = max(mx, a[i]);
        cout << mx << '\n';
        return 0;
    }
    else if (m == 2)
    {
        int mx = 0;
        for (int i = 1;i <= n; i++)
            for (int j = i + 1; j <= n; j++)
                mx = max(mx, a[i] & a[j]);
        cout << mx << endl;
        return 0;
    }
    else if (m == n)
    {
        int res = a[1];
        for (int i = 2; i <= n; i++)
            res &= a[i];
        cout << res << '\n';
        return 0;
    }
    dfs(1);
    cout << mxres << '\n';
    fclose(stdin);
    fclose(stdout);
    return 0;
}