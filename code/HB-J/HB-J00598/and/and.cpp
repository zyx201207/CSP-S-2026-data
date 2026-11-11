#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n, k;
    long long a[100001];
    long long maxa=-1;
    cin>>n>>k;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    for(int bit=(1<<n);bit>=0;bit--)
    {
        int o=0;
        long long g[10001];
        for(int j=1;j<=bit;j++)
        {
            if((bit>>j)%2)
            {
                o++;
                g[o]=a[j];
            }
        }
        if(o!=k)
        {
            continue;
        }
        sort(g+1,g+o+1);
        long long s=g[o];
        for(int i=o-1;i>=1;i--)
        {
            cout<<g[i]<<" ";
            s=(s&g[i]);
        }
        maxa=max(s,maxa);
    }
    cout<<maxa;
    return 0;
}