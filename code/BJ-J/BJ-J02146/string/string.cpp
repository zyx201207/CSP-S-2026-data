#include <iostream>

using namespace std;
long long n, ans = 0, p1, p2;

struct point
{
    long long num;
    char ch;
}a[200005];

int main()
{
    ios::sync_with_stdio(false);
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    cin >> n;
    for (int i = 1; i <= n; i ++)
    {
        cin >> a[i].num >> a[i].ch;
    }
    p1 = 1;
    p2 = n;
    while(p1 < p2)
    {
        if(a[p1].num <= a[p2].num)
        {
            if(a[p1].ch != a[p2].ch)
            {
                ans += a[p1].num;
            }
            a[p2].num -= a[p1].num;
            a[p1].num = 0;
        }
        else
        {
            if(a[p1].ch != a[p2].ch)
            {
                ans += a[p2].num;
            }
            a[p1].num -= a[p2].num;
            a[p2].num = 0;
        }
        if(a[p1].num <= 0)
        {
            p1 ++;
        }
        if(a[p2].num <= 0)
        {
            p2 --;
        }
    }
    cout << ans;
	return 0;
}
