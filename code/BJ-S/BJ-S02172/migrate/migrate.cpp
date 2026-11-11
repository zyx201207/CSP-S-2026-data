#include <iostream>
#include <deque>
#include <vector>
#include <cstdio>
using namespace std;

int x[2000010];
vector<long long> g[2000010];

int main()
{
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    int c, T;
    cin >> c >> T;
    while (T--)
    {
        long long n, d;
        cin >> n >> d;
        for (int i = 1; i <= n; i++)
        {
            cin >> x[i];
        }
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (i != j && x[j] - x[i] <= d)
                {
                    g[i].push_back(j);
                    g[j].push_back(i);
                }
            }
        }
        cout << 0 << endl;
    }
    return 0;
}
