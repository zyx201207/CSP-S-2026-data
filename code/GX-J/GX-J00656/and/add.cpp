#include <bits/stdc++.h>
using namespace std;
int n,m;
int a[100000];
int main ()
{
    freopen("add.in","r",stdin);
    freopen("add.out","w",stdout);
    int maxn=-1;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    for(int i=1;i<=n;i++)
    {
        int q=0;
        for(int j=i+1;j<m+i;j++)
        {
            if(a[j]!=0)
            {
                q=(a[i]&a[j]);
            }
        }
        if(q>maxn)
        {
            maxn=q;
        }
    }
    cout<<maxn;
    return 0;
}
