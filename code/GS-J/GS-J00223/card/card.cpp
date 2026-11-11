#include <bits/stdc++.h>

using namespace std;

int n,m,a[5005],d[3005],ans[3005]={0},step,v[5005];

int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin >> n >> m;
    for(int i=1; i<=n; i++)
    {
        cin >> a[i];
    }
    memset(ans,0,sizeof ans);
    for(int i=1; i<=n; i++)
    {
        memset(d,-1,sizeof d);
        memset(v,0,sizeof v);
        step=0;
        for(int j=i; j<=n; j++)
        {
            if(d[a[j]]==-1 || d[a[j]]>=step)
            {
                v[step]=a[j];
                d[a[j]]=step;
                step++;
            }
            else
            {
                step=d[a[j]]+1;
            }
        }
        for(int j=0; j<step; j++)
            ans[v[j]]++;
    }
    for(int i=1; i<=m; i++)
        cout << ans[i] << ' ';
    return 0;
}
