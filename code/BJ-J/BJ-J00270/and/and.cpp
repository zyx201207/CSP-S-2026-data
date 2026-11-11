#include <iostream>
#include <cstdio>

using namespace std;

int n, m;
int a[214514], b[214514];
bool fbj[214514], ffbj[214514];

int main()
{
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);
    int i, j;
    cin >> n >> m;
    for (i = 1; i <= n; i++)
    {
        cin >> a[i];
        b[i] = a[i];
    }
    for (i = 30; i >= 0; i--)
    {
        int f = (1 << i), sum = 0;
        for (j = 1; j <= n; j++)
        {
            if (fbj[j]) continue;
            if (a[j] >= f)
            {
                a[j] -= f;
                ffbj[j] = false;
                sum++;
            }
            else
            {
                ffbj[j] = true;
            }
        }
        /*
        for (j = 1; j <= n; j++)
        {
            cout << i << " " << f << " " << fbj[j] << " " << ffbj[j] << " " << a[j] << " " << sum << endl;
        }
        //*/
        if (sum >= m)
        {
            //cout << f << endl;
            for (j = 1; j <= n; j++)
            {
                fbj[j] = fbj[j] || ffbj[j];
                //if (!fbj[j]) cout << j << " ";
                //else cout << -j << " ";
            }
            //cout << endl;
        }
    }
    int ans = 0x7fffffff;
    for (i = 1; i <= n; i++)
    {
        if (!fbj[i])
        {
            ans = ans & b[i];
        }
    }
    cout << ans << endl;
    return 0;
}
