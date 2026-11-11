#include <bits/stdc++.h>
using namespace std;

int n, m, a[200005], ans;
bool ejz[200005][35], flag[200005];

int ksm(int a, int b)
{
    if (b == 0) return 1;
    int c = ksm(a, b / 2);
    if (b % 2 == 0) return c * c;
    else return c * c * a;
}

int main()
{
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        int t = a[i], cnt = 0;
        while (t)
        {
            ejz[i][cnt] = t % 2;
            cnt++;
            //cout << t % 2;
            t /= 2;
        }
    }
    for (int j = 30; j >= 0; j--)
    {
        int cnt = 0;
        for (int i = 1; i <= n; i++)
        {
            if (!flag[i] && ejz[i][j])
            {
                cnt++;
            }
        }
        //    cout << "t";
        if (cnt >= m)
        {
            for (int i = 1; i <= n; i++)
            {
                if (!ejz[i][j]) flag[i] = 1;
            }
         //   cout << j << " " << cnt << "\n";
            //cout << pow(2, j);
            ans += ksm(2, j);
            //cout << ans;
        }
    }
    cout << ans;
    return 0;
}
