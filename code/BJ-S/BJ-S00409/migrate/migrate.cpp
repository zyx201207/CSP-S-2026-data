#include<iostream>
#include<vector>
#include<queue>
using namespace std;
int n, d, c, t, x[2000010];
void solve()
{
    cin >> n >> d;
    for(int i = 1; i <= n; ++i)
    {
        cin >> x[i];
    }
    int sum = 0;
    for(int i = 4; i <= n; ++i)
    {
        if(x[i] - x[i - 2] <= d && x[i - 1] - x[i - 3] <= d && x[i] - x[i - 3] > d)
        {
            ++sum;
        }
    }
    cout << sum << endl;
}
int main()
{
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    cin >> c >> t;
    while(t--)
    {
        solve();
    }
    return 0;
}
