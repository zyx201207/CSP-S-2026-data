#include <iostream>
#include <algorithm>
using namespace std;
long long a[500005],b[500005];
int main()
{
    ios::sync_with_stdio(false);
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    int n;
    long long m;
    cin >> n >> m;
    for(int i = 1;i <= n;i++)
    {
        cin >> a[i];
    }
    sort(a + 1,a + n + 1);
    b[1] = 0;
    for(int i = 2;i <= n;i++)
    {
        b[i] = b[i - 1] + (i - 1) * (a[i] - a[i - 1]);
    }
    int tmp = 1;
    while(b[tmp + 1] <= m && tmp < n)
    {
        tmp++;
    }
    int ans = 0;
    ans = tmp;
    long long s;
    for(int i = tmp + 1;i <= n - 1;i++)
    {
        bool pl = 0;
        for(int j = 2;j <= n - i + 1;j++)
        {
            s = b[j + i - 1] - b[j] - (long long)(a[j + i - 1] - a[j]) * (j - 1);
            if(s <= m)
            {
                ans = i;
                pl = 1;
                break;
            }
        }
        if(pl == 0) break;
    }
    cout << ans << endl;
    return 0;
}