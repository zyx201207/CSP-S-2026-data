#include<iostream>
#include<algorithm>
using namespace std;
int n, a, b[200010][32], m, cnts, vis[200010], ans, is[200010];
int main()
{
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);
    cin >> n >> m;
    cnts = n;
    for(int i = 1; i <= n; ++i)
    {
        cin >> a;
        int cnt = 0;
        while(a)
        {
            b[i][cnt] = a % 2;
            a /= 2;
            ++cnt;
        }
        for(int j = 0; j <= 15; ++j)
        {
            swap(b[i][j], b[i][30 - j]);
        }
    }
    for(int i = 0; i <= 30; ++i)
    {
        int last = cnts;
        for(int j = 1; j <= n; ++j)
        {
            if(vis[j])
            {
                is[j] = 0;
                continue;
            }
            if(b[j][i] == 0)
            {
                cnts--;
                vis[j] = 1;
                is[j] = 1;
            }
        }
        if(cnts >= m)
        {
            ans += (1 << (30 - i));
        }
        else
        {
            cnts = last;
            for(int j = 1; j <= n; ++j)
            {
                if(is[j])
                {
                    vis[j] = 0;
                }
            }
        }
    }
    cout << ans;
    return 0;
}
