#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

const int MAXN = 5e5+5;
int n, m, a[MAXN];

int main()
{
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);

    cin >> n >> m;
    for(int i = 1;i <= n;i++)
    {
        cin >> a[i];
    }
    int cnt = 0;
    for(int i = 1;i <= n;i++)
    {
        if(a[i] < 0)
        {
            a[i] += 1;
        }
        if(a[i] < a[i+1]-2)
        {
            cnt += i;
            break;
        }
    }
    cout << cnt;

    return 0;
}
