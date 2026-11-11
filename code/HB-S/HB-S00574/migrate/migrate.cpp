#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5005;
int c,T,n,pre[N],nxt[N];
ll d,x[N];
bool bk[N];
int main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    scanf("%d%d",&c,&T);
    while(T--)
    {
        scanf("%d%lld",&n,&d);
        for(int i=1;i<=n;i++)
        {
            scanf("%lld",&x[i]);
        }
        int j=1;
        for(int i=1;i<=n;i++)
        {
            while(j<i&&x[i]-x[j]>d)
            {
                if(j!=i-1)nxt[j]=i-1;
                j++;
            }
        }
        for(int i=j;i<=n;i++)nxt[i]=n;
        j=n;
        for(int i=n;i>0;i--)
        {
            while(j>i&&x[j]-x[i]>d)
            {
                if(j!=i+1)pre[j]=i+1;
                j--;
            }
        }
        for(int i=j;i>0;i--)pre[i]=1;
        ll ans=0;
        for(int i=1;i<=n;i++)
        {
            for(int j=i+1;j<=n;j++)
            {
                int cnt=0;
                bool fl=0;
                for(int k=i+1;k<j;k++)bk[k]=0;
                for(int k=i;k<j;k=nxt[k])
                {
                    cnt++;
                    bk[k]=1;
                    if(k<j&&k==nxt[k])
                    {
                        fl=1;
                        break;
                    }
                }
                if(fl)continue;
                bk[j]=1;
                for(int k=j;k>i;k=pre[k])
                {
                    cnt--;
                    if(!bk[k])fl=1;
                    if(k>i&&k==pre[k])break;
                }
                ans+=fl;
            }
            // printf("%d:%d,%d\n",i,pre[i],nxt[i]);
        }
        printf("%lld\n",ans);
    }
    return 0;
}
