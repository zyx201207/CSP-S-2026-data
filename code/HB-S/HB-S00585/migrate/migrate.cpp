#include<iostream>
using namespace std;
const int N=2e6+5;
long long x[N],f[N],Q[N],dis[N];
int nxt[N],pos[N];
int main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int c,T,n;
    long long d,ans;
    cin>>c>>T;
    while(T--)
    {
        cin>>n>>d;
        for(int i=1;i<=n;i++)
            cin>>x[i];
        ans=0;
        for(int i=1;i<=n;i++)
        {
            int h=0,t=0;
            for(int j=i+1;j<=n;j++)
            {
                f[j]=0;
                dis[j]=N;
            }
            f[i]=1;
            dis[i]=0;
            Q[t++]=i;
            while(h<t)
            {
                int u=Q[h];
                h++;
                for(int j=u+1;j<=n;j++)
                {
                    if(x[j]-x[u]>d)
                        break;
                    if(dis[u]+1==dis[j])
                        f[j]=min(f[j]+f[u],3ll);
                    if(dis[u]+1<dis[j])
                    {
                        dis[j]=dis[u]+1;
                        f[j]=f[u];
                        Q[t++]=j;
                    }
                }
            }
            for(int j=i+1;j<=n;j++)
                if(f[j]==2)
                    ans++;
        }
        cout<<ans<<"\n";
    }
    return 0;
}