#include <bits/stdc++.h>
using namespace std;
const int numm=500005;
long long n,m,a[numm],f[numm];
int main()
{
    freopen("crystal.out","w",stdout);
    freopen("crystal.in","r",stdin);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        scanf("%lld",&a[i]);
    }
    sort(a,a+n);
    for(int i=1;i<=n;i++)
    {
        f[i]=f[i-1]+(i-1)*(a[i]-a[i-1]);
        if(f[i]==m)
        {
            cout<<i<<endl;
            break;
        }
        else if(f[i]>m)
        {
            cout<<i-1<<endl;
            break;
        }

    }
    return 0;
}
