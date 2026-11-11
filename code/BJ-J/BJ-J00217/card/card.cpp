#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[500005],b[500005],p[300005],ans[300005],n,m,cnt;
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int i,j,k;
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for (i=1;i<=n;i++)
        cin>>a[i];
    for (i=1;i<=n;i++)
    {
        memset(b,0,sizeof b);
        memset(p,0,sizeof p);
        cnt=0;
        for (j=i;j<=n;j++)
        {
            if (!p[a[j]])
            {
                b[++cnt]=a[j];
                p[a[j]]=cnt;
            }
            else
            {
                for (k=p[a[j]]+1;k<=cnt;k++)
                {
                    p[b[k]]=0;
                    b[k]=0;
                }
                cnt=p[a[j]];
            }
        }
        for (j=1;j<=m;j++)
            ans[j]+=(p[j]!=0);
    }
    for (i=1;i<=m;i++)
        cout<<ans[i]<<" ";
    cout<<endl;
}
