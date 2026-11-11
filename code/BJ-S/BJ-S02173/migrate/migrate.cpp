#include<bits/stdc++.h>
using namespace std;

int n;
unsigned long long d;
long long x[2000004];
unsigned long long ans = 0;
unsigned long long min_fly_time;
int many_ans;

void have(int isl, int islend, unsigned long long fly_time)
{
    if (isl > islend || fly_time >= min_fly_time)
    {
        return;
    }
    if (isl == islend && fly_time == min_fly_time)
    {
        many_ans++;
        return;
    }
    if (isl == islend && fly_time <= min_fly_time)
    {
        many_ans = 1;
        min_fly_time = fly_time;
        return;
    }
    int i = 1;
    while(x[isl] + d > x[isl + i] && isl + i <= islend)
    {
        have(isl + i, islend, fly_time++);
        i++;
    }
    return;
}

void find_migrate()
{
    cin >> n;
    cin >> d;
    ans = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> x[i];
    }

    for (int i = 0; i < n - 3; i++)
    {
        for (int j = i + 3; j < n; j++)
        {
            min_fly_time = 0xffffffffffffffff;
            many_ans = 0;
            have(i, j, 0);
            if (many_ans == 2)
            {
                ans++;
            }
        }
    }
    cout << ans;

    return;
}

int main()
{
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);

    int c, t;
    cin >> c >> t;
    for (int i = 0; i < t; t++)
    {
        find_migrate();
    }

    return 0;
}
