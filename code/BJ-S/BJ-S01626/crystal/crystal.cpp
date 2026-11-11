#include <iostream>
#include <cmath>
using namespace std;

long long a[500010];
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    long long n,m;
    cin >>n >> m;
    long long maxn = -1e12;
    long long minn = 1e12;
    bool flag = false;
    for (int i = 1; i <= n;i++)
    {
        cin >> a[i];
        maxn = max(maxn,a[i]);
        minn = min(minn,a[i]);
        if ((a[i] - a[i - 1] != a[i - 1] - a[i - 2]) && i != 1 && i != 2) flag = true;
    }
    if (m >= 1e12 || flag == false)
    {
        int a = sqrt(m);
        a -= 2;
        while (a *(a + 1) / 2 < m) a += 1;
        cout << a<<endl;
        return 0;
    }
    long long ans = 0;
    for (long long i = minn; i <= maxn;i++)
    {
        long long t = m;
        long long cnt = 0;
        for (int j = 1; j <= n; j++)
        {
            if (a[j] <= i)
            {
                if (t >= i - a[j]) t -= i - a[j];
                else break;
                cnt++;
            }
        }
        ans = max(ans,cnt);
    }
    cout <<ans <<endl;
    return 0;
}
