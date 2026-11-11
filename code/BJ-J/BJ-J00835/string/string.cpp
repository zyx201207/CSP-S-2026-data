#include <iostream>
#include <cmath>
using namespace std;

int n;
long long a[200005];
char c[200005];
void f2()
{
    int cur = 0;
    for (int i = 1; i <= n; i ++)
    {
        int aa;
        char cc;
        cin >> aa >> cc;
        if (i > 1 && cc == c[cur])
        {
            cur -= 1;
        }
        int ccur = ++cur;
        a[ccur] += aa;
        c[ccur] = cc;
    }
    //for (int i = 1; i <= cur; i ++) cout << a[i] << " " << c[i] << '\n';
    long long cnt = 0;
    int l = 1 , r = n;
    while (l <= r)
    {
        bool flagl = true , flagr = true;
        if (c[l] != c[r])
        {
            if (a[l] == a[r])
                cnt += a[l];
            else
            {
                if (a[l] < a[r])
                {
                    cnt += a[l];
                    //cout << a[l] << " " << a[r] << '\n';
                    a[r] -= a[l];
                    a[l] = 0;
                    flagr = false;
                }
                else if (a[l] > a[r])
                {
                    cnt += a[r];
                    //cout << a[l] << " " << a[r] << '\n';
                    a[l] -= a[r];
                    a[r] = 0;
                    flagl = false;
                }
            }
        }
        else
        {
            if (a[l] != a[r])
            {
                if (a[l] < a[r])
                {
                    a[r] -= a[l];
                    a[l] = 0;
                    flagr = false;
                }
                else if (a[l] > a[r])
                {
                    a[l] -= a[r];
                    a[r] = 0;
                    flagl = false;
                }
            }
        }
        l += flagl;
        r -= flagr;
    }
    cout << cnt;
}
int main()
{
    freopen("string.in" , "r" , stdin);
    freopen("string.out" , "w" , stdout);
    cin >> n;
    f2();
    return 0;
}
