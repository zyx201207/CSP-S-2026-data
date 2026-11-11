#include <bits/stdc++.h>
using namespace std;
const int maxn = 5e5 + 5;
int n, m, a[maxn], diff[maxn], b[maxn],ans[maxn];
vector<int> pos[maxn];
int main()
{
    freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
    cin >> n >> m;
    for(int i = 1; i <= n; i++) cin >> a[i];
    if(n == m)
    {
        for(int i = 1; i <= n; i++) cout << n - i + 1 << " ";
        return 0;
    }
    for(int i = 1; i <= n; i++)
    {
        for(int j = i; j <= n; j++) pos[a[j]].push_back(j);
        for(int j = 1; j <= m; j++)
        {
            if(pos[j].size() > 1)
            {
                diff[pos[j][0]] = 1;
                diff[pos[j][pos[j].size()-1]] = -1;
            }
        }
        for(int i = 1; i <= n; i++) b[i] = b[i - 1] + diff[i];
        for(int i = 1; i <= n; i++) if(b[i] == 0) ans[a[i]]++;
    }
    for(int i = 1; i <= m; i++) cout << ans[i] << " ";
	return 0;
}
