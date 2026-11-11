#include <bits/stdc++.h>
using namespace std;

long long a[200001],b[200001];long long maxn=-999;bool c[200001];
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m;cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    if(m==n)
    {
        int cnt=a[1];
        for(int i=1;i<=n;i++)
            cnt&=a[i];
        cout<<cnt;
        return 0;
    }
    sort(a+1,a+1+n);
    if(m==1)
    {
        cout<<a[1];
        return 0;
    }
    for(int k=1;k<=n;k++)
    {
        for(int i=1;i<=n;i++)c[i]=0;
        for(int j=1;j<=m;j++)
        {
            int d=-9999;b[k]=0;
            for(int i=1;i<=n;i++)
            {
                if(c[i]||i==k)continue;
                if(b[k]<(a[k]&a[i]))
                {
                    b[k]=(a[i]&a[k]);
                    c[i]=1;c[d]=0;d=i;
                }
            }a[k]=b[k];
        }
        maxn=max(b[k],maxn);
    }
    cout<<maxn;
    return 0;
}
