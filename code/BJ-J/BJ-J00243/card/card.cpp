#include<bits/stdc++.h>
using namespace std;
const int M=5*1e5+20;
int a[M],cnt[M],ans[M],flg[M];
int main()
{

    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    for(int k=1;k<=n;k++)
    {
        memset(cnt,0,sizeof(cnt));
        memset(flg,0,sizeof(flg));
        for(int i=k;i<=n;i++)
        {
            if(flg[a[i]]==0)
            {
                cnt[a[i]]=i;
                flg[a[i]]=1;
            }
            else
            {
                for(int j=cnt[a[i]];j<i;j++)
                {
                    flg[a[j]]=0;
                    cnt[a[j]]=0;
                }
                cnt[a[i]]=i;
                flg[a[i]]=1;
            }

        }
        for(int j=1;j<=m;j++)
        {
            ans[j]+=flg[j];
        }
    }
    for(int i=1;i<=m;i++)
    {
        cout<<ans[i]<<" ";
    }
    return 0;
}
