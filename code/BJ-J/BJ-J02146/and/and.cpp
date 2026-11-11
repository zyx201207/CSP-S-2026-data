#include <iostream>

using namespace std;
long long n, m, inn, bigw, ans = 0;
bool a[200005][32] = {};
bool f[200005] = {};
int num[32] = {};

int main()
{
    ios::sync_with_stdio(false);
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);
    cin >> n >> m;
    for (long long i = 1; i <= n; i ++)
    {
        f[i] = 1;
    }
    for (long long i = 1; i <= n; i ++)
    {
        cin >> inn;
        for (long long j = 29; j >= 0; j --)
        {
            if(inn >= (1 << j))
            {
                inn -= (1 << j);
                a[i][j] = 1;
                num[j] ++;
            }
        }
    }
    for (int i = 29; i >= 0; i --)
    {
        if(num[i] >= m)
        {
            bigw = i;
            break;
        }
    }
    for (long long i = bigw; i >= 0; i --)
    {
        if(num[i] >= m)
        {
            ans += (1 << i);
            for (long long j = 1; j <= n; j ++)
            {
                if(f[j] && a[j][i] == 0)
                {
                    f[j] = 0;
                    for (long long k = 29; k >= 0; k --)
                    {
                        if(a[j][k])
                        {
                            num[k] --;
                        }
                    }
                }
            }
        }
    }
    cout << ans;
	return 0;
}
