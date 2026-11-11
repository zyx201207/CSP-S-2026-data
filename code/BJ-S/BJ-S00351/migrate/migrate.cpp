#include<bits/stdc++.h>
using namespace std;
const int N = 2e6 + 10;
int c, t;
int x[N];
int n, d;
bool check(int a, int b)
{
    for(int i = a;i <= b;i++)
        if(i + 1 <= b)
        {
            if(abs(x[i + 1] - x[i]) > d) return false;
        }
    if(abs(x[b] - x[a]) + 1 == 2 * d) return true;
    else return false;
}
int main()
{
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    cin >> c >> t;
    while(t--)
    {

        cin >> n >> d;
        for(int i = 1;i <= n;i++)
            cin >> x[i];
        int cnt = 0, i = 1;
        for(int j = i;j <= n;j++)
        {
            if(i > n) break;
            if(abs(x[j] - x[i]) <= d)
            {
                if(j == n)
                {
                    i++;
                    j = i;
                }
                continue;
            }
            if(check(i, j))
                cnt++;
            if(j == n)
            {
                i++;
                j = i;
            }
        }
        cout << cnt;
    }
    return 0;
}
