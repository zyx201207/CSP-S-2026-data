//GZ-S00107 岑栋彬 贵州省兴义市第五中学
#include <bits/stdc++.h>
using namespace std;
int n,m,a[10005],sum;
int main()
{
    freopen ("crystal.in","r",stdin);
    freopen ("crystal.out","w",stdout);
    cin >> n >> m;
    for (int i=1;i<=n;i++)
    {
        cin >> a[i];
    }
    int Q=a[1];
    sum++;
    for (int i=1;i<=n;i++)
    {
        if (a[i]>a[i+1])
            Q=a[i+1];
    }
    cout << sum;
    return 0;
}
