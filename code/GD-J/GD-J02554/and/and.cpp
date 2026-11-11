#include <bits/stdc++.h>
using namespace std;

int a[100005];

int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m,maxn=0,maxn2=0,minn=1e9,minnid=0;
    cin >> n >> m;
    for (int i=1;i<=n;i++)
    {
        cin >> a[i];
        maxn=max(maxn,a[i]);
        if (a[i]<minn)
        {
            minn=a[i];
            minnid=i;
        }

    }
    for (int i=1;i<=n;i++)
    {
        if (a[i]>maxn2&&a[i]!=maxn)
        {
            maxn2=a[i];
        }
    }
    if (m==1) cout << maxn;
    if (m==2) cout << (maxn&maxn2);
    if (m==n)
    {
        int h;
        for (int i=1;i<=n;i++)
        {
            h=h+h&a[i];
        }
        cout << h;
    }
    if (m==n-1)
    {
        int h;
        int g=a[minnid];
        a[minnid]=a[n];
        a[n]=g;
        for (int i=1;i<n;i++)
        {
            h=h+h&a[i];
        }
        cout << h;
    }
    return 0;
}
