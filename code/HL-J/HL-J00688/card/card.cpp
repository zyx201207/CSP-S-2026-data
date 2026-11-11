#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],ans[300005];
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    for(int i=1;i<=n;i++)
    {
        int g=0,d[500005];
        for(int j=i;j<=n;j++)
        {
            for(int k=1;k<=g;k++)
            {
                if(d[k]==a[j])
                    g=k-1;
            }
            g++;
            d[g]=a[j];
        }
        for(int k=1;k<=g;k++)
        {
            ans[d[k]]++;
        }
    }
    for(int i=1;i<=m;i++)
    cout<<ans[i]<<' ';
    return 0;
}
