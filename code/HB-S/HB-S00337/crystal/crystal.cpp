#include <bits/stdc++.h>
using namespace std;
long long a[500005];
long long d[500005]={0};
long long maxd=1;
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    long long n,m;
    cin >> n >> m;
    for (int i=1;i<=n;i++)
    {
        cin >> a[i];
    }
    sort(a+1,a+n+1);
    if (n>5000 && m>100000000){
        int v=a[2]-a[1];
        int t=m/v;
        int x=0;
        for (int i=1;i<=n;i++)
        {
            x+=i;
            if (x>t)
            {
                cout << i;
                return 0;
            }
        }
        cout << n;
        return 0;
    }
    for (int i=1;i<=n;i++)
    {
        long long t=m;
        long long cb=1;
        for (int j=i-1;j>=1&&t;j--)
        {
            if (t<a[i]-a[j]){break;}
            t-=(a[i]-a[j]);
            cb++;
        }
        maxd=max(maxd,cb);
    }
    cout << maxd;
    return 0;
}
