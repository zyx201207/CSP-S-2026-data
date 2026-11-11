#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e6+5;
int c,t,n;
ll d,x[N],f[N],g[N],cnt;
void bfs(int a)
{
    queue<int> q;
    q.push(a);
    f[a]=0;
    g[a]=1;
    while(!q.empty())
    {
        int t=q.front();
        q.pop();
        for (int i=t+1;i<=n;i++)
        {
            ll nw=x[i]-x[t];
            //cout<<f[i]<<' '<<f[t]<<' '<<t<<' '<<y<<' '<<nw<<' '<<d<<' '<<endl;
            if (nw<=d && f[i]>f[t]+1ll)
            {
                //cout<<f[i]<<' ';
                f[i]=f[t]+1ll;
                g[i]=g[t];
                q.push(i);
                //cout<<1<<' '<<t<<' '<<i<<' '<<g[i]<<' '<<f[t]+1<<' '<<a<<' '<<endl;
            }
            else if (nw<=d && f[i]==f[t]+1ll)
                g[i]+=g[t];
            else if (nw>d)
                break;
        }
    }
    return ;
}
int main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    scanf("%d %d",&c,&t);
    while(t--)
    {
        cnt=0;
        scanf("%d %lld",&n,&d);
        for (int i=1;i<=n;i++)
            scanf("%lld",&x[i]);
        for (int i=1;i<=n;i++)
        {
            memset(f,0x3f,sizeof(f));
            memset(g,0,sizeof(g));
            bfs(i);
            for (int j=1;j<=n;j++)
                if (g[j]==2)
                    cnt++;
        }
        printf("%lld\n",cnt);
    }
    return 0;
}