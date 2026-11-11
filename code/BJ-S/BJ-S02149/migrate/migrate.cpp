#include<bits/stdc++.h>
#define int long long
using namespace std;
int x[5010],pre[5010],nxt[5010];
signed main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int c,t;
    cin>>c>>t;
    while(t--)
    {
        int n,d;
        cin>>n>>d;
        for(int i=1;i<=n;i++)cin>>x[i];
        int cur=1;
        pre[1]=1;
        for(int i=2;i<=n;i++)
        {
            while(x[i]-x[cur]>d)cur++;
            pre[i]=cur;
        }
        cur=n;
        nxt[n]=n;
        for(int i=n-1;i>=1;i--)
        {
            while(x[cur]-x[i]>d)cur--;
            nxt[i]=cur;
        }
        int ans=0;
        for(int i=2;i<=n;i++)
        {
            int cnt[5010],pos=i;
            for(int j=i-1;j>=1;j--)
            {
                if(j>=pre[i])cnt[j]=1;
                else{
                    if(j<pre[pos])pos=pre[pos];
                    cnt[j]=cnt[pos]-cnt[nxt[j]+1];
                }
                if(cnt[j]==2)ans++;
                cnt[j]+=cnt[j+1];
            }
        }
        cout<<ans<<'\n';
    }
    return 0;
}