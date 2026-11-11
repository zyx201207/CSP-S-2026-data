#include <iostream>
#include <cstdio>
using namespace std;
long long a[200005], sum = 0;
void f(int n, int m,int y,int step,int cnt)
{
    if(step >= y)
    {
        cnt++;
        return;
    }
    for(int i = 1;i <= n;i++)
    {
        if(a[i]-step > m)break;
        f(n, m, y, a[i], cnt);
    }
    if(cnt == 2)
    {
        sum++;
    }

}
int main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    long long c, t;
    cin >> c >>t;
    for(int i = 1;i <= t;i++)
    {
        int n, m;
        cin >> n >> m;
        for(int j = 1;j <= n;j++)
        {
            cin >> a[j];
        }
        for(int j = 1;j <= a[n];j++)
        {
            for(int t = 1;t <= a[n];t++)
            {
                f[j][t];
            }
        }
    }
    cout << sum;
}
