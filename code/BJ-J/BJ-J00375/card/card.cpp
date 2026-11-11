#include<bits/stdc++.h>
using namespace std;
int a[500005],la[500005],f[500005],cnt[500005];
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;++i)cin>>a[i];
    for(int k=1;k<=n;++k)
    {
        memset(la,0,sizeof(la));
        int now=1;
        for(int i=k;i<=n;++i)
        {
            if(la[a[i]]==0)
            {
                la[a[i]]=now;
                f[now]=a[i];
                ++now;
            }
            else
            {
                for(int j=la[a[i]]+1;j<now;++j)
                {
                    la[f[j]]=0;
                    f[j]=0;
                }
                now=la[a[i]]+1;
            }
        }
        for(int i=1;i<now;++i)cnt[f[i]]++;
    }
    for(int i=1;i<=m;++i)cout<<cnt[i]<<' ';
    cout<<endl;
    return 0;
}
//t=10:50 start thinking
//t=10:55 for each card,it will be kill only when it is between 2 same card
//t=11:03 wirte baoli O(n^2) first
//t=11:23 baoli complete,guseing true ans