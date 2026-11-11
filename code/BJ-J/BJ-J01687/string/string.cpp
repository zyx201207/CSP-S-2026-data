#include <iostream>
using namespace std;
#define int long long

int n , ans = 0;
struct stu
{
    int x;
    char ch;
}a[200005];

signed main()
{
    freopen("string.in" , "r" , stdin);
    freopen("string.out" , "w" , stdout);
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        int x;
        char ch;
        cin >> x >> ch;
        a[i].x = x;
        a[i].ch = ch;
    }
    int l = 1 , r = n;
    while (l < r)
    {
        if (a[l].ch == a[r].ch)
        {
            if (a[l].x > a[r].x)
            {
                a[l].x -= a[r].x;
                r--;
            }
            else if (a[l].x < a[r].x)
            {
                a[r].x -= a[l].x;
                l++;
            }
            else
            {
                l++ , r--;
            }
        }
        else
        {
            ans += min(a[l].x , a[r].x);
            if (a[l].x > a[r].x)
            {
                a[l].x -= a[r].x;
                r--;
            }
            else if (a[l].x < a[r].x)
            {
                a[r].x -= a[l].x;
                l++;
            }
            else
            {
                l++ , r--;
            }
        }
    }
    cout << ans << endl;
    return 0;
}
