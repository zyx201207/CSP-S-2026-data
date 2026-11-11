#include<bits/stdc++.h>
using namespace std;
int n,m,k,a[500005],b[500005],vis[500005],cnt[500005];
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    for(int i=1;i<=n;i++)
    {
        memset(vis,0,sizeof(vis));
        k=0;
        for(int j=i;j<=n;j++)
        {
            int p=0;
            for(int l=1;l<=k;l++)
                if(b[l]==a[j])
                    p=l;
            if(!p)b[++k]=a[j];
            else k=p,b[k]=a[j];
        }
        for(int j=1;j<=k;j++)
            vis[b[j]]=1;
        for(int j=1;j<=k;j++)
            cnt[b[j]]+=vis[b[j]];
    }
    for(int i=1;i<=m;i++)
        printf("%d ",cnt[i]);
    puts("");
    return 0;
}
