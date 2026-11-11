#include <bits/stdc++.h>
using namespace std;
int a[200005];
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m;
    cin >> n >> m;
    for (int i=1;i<=n;i++)
    {
        cin >> a[i];
    }
    for (int z=1;z<m;z++)
    {
        for (int i=1;i<=n;i++)
        {
            int maxn=0;
            for (int j=1;j<=n;j++)
            {
                if (i==j)
                    continue;
                if (a[i]&a[j]>maxn)
                {
                    int l=a[i]&a[j];
                    maxn=l;
                }
            }
            a[i]=maxn;
        }
    }
    int maxa=0;
    for (int i=1;i<=n;i++)
    {
        if (a[i]>maxa)
            maxa=a[i];
    }
    cout << maxa;
    return 0;
}
