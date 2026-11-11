#include <bits/stdc++.h>
using namespace std;
long long n,f[10000005],ans,m,a[10000005],w[200005][32],aw[32],sw[2000005];
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=m;j>=1;j--)
        {
            if(j==1)f[j]=max(f[j],a[i]);
            else f[j]=max(f[j-1]&a[i],f[j]);
        }
    }
    cout<<f[m];
    return 0;
}
