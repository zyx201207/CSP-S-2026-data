#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;
long long t, ans;
struct S
{
    int x;
    char ch;
    void read()
    {
        cin >> x >> ch;
    }
} a[300005];
void check(int k)
{
    int sum = a[k].x;
    char ch = a[k].ch;
    for(int i = t; i >= 1; i --)
    {
        if(sum == 0) break;
        if(a[i].ch == ch)
        {
            if(a[i].x <= sum)
            {
                sum -= a[i].x;
                a[i].x = 0;
                t --;
            }
            else if(a[i].x > sum)
            {
                a[i].x -= sum;
                sum = 0;
            }
        }
        else
        {
            if(a[i].x <= sum)
            {
                ans += a[i].x;
                sum -= a[i].x;
                a[i].x = 0;
                t --;
            }
            else if(a[i].x > sum)
            {
                ans += sum;
                a[i].x -= sum;
                sum = 0;
            }
        }
    }
}
int main()
{
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    int n;
    cin >> n;
    for(int i = 1; i <= n; i ++) a[i].read();
    t = n;
    for(int i = 1; i <= n; i ++)
    {
        if(i == t) break;
        check(i);
    }
    cout << ans;
    return 0;
}
