#include <bits/stdc++.h>
using namespace std;
int n,m;
int a[500005],ans[300005];
int ev(int i)
{
    int d[500005];
    int s[500005];
    memset(d,0,sizeof(d));
    memset(s,0,sizeof(s));
    for (int k=i;k<=n;k++)
    {
        if (d[a[k]]>=1 && s[d[a[k]]]!=-1)
        {
            fill(s+d[a[k]]+1,s+k,-1);
            if (s[d[a[k]]]==-1)
            {
                s[d[a[k]]]=0;

            }
            else
            {
                s[d[a[k]]]=-1;
            }
            d[a[k]]=k;

        }
        else
        {
            d[a[k]]=k;
        }
    }
    for (int k=1;k<=max(n,m);k++)
    {
        if (d[k]>=1 && s[d[k]]!=-1)
        {
            ans[k]++;
        }
    }

    return 0;
}
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for (int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    for (int i=1;i<=n;i++)
    {
        ev(i);
    }
    for (int i=1;i<=m;i++)
    {
        cout<<ans[i]<<" ";
    }
    fclose(stdin);
    fclose(stdout);
}
