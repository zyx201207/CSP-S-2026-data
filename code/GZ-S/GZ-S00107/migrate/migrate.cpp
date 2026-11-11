//GZ-S00107 岑栋彬 贵州省兴义市第五中学
#include <bits/stdc++.h>
using namespace std;
int c,t,n,d,x[10005],a;
int main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin >> c >> t;
    for (int i=1;i<=t;i++)
    {
        cin >> n >> d;
        for (int j=1;j<=n;j++)
        {
           cin >> x[i];
        }
    }
    for (int i=1;i<=n;i++)
    {
        if (x[i]+x[i+1]<=n||x[i]+x[i+2]<=n)
        {
            a++;
        }
    }
    for (int i=1;i<=t;i++)
        cout <<a << endl;
    return 0;
}
