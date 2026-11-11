#include <cstdio>
#include <iostream>
#include <cmath>
using namespace std;

const int MAXN = 2e6+5;
int c, t, n, d, a[MAXN];

int main()
{
    freopen("imgrate.in", "r", stdin);
    freopen("imgrate.out", "w", stdout);

    cin >> c >> t;
    int cnt = 0;
    while(t--)
    {
        cin >> n >> d;
        for(int i = 1;i <= n;i++)
        {
            cin >> a[i];
            if(abs(a[i+2])>abs(a[i+1]) && abs(a[i+1])>abs(a[i]))
            {
                if(abs(a[i+2])-abs(a[i+1])<=d && abs(a[i+1])-abs(a[i])<=d)
                {
                    cnt += 1;
                }
                else
                {
                    continue;
                }
            }
        }
        cout << cnt << endl;
    }

    return 0;
}