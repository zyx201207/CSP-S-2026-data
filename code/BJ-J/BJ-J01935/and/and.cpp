#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m,a[10000],a1[10000],a2[10000],maxn=0;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    int l=1;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<m;j++)
        {
            a2[i]=a1[l]&a1[l+1];
            l++;
        }
        l=i;
        maxn=max(a2[i],maxn);
    }
    cout<<maxn;
    return 0;
}