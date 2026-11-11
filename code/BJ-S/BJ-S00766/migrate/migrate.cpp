#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int maxn=3e2+11;
const ll inf=4e18;
ll c,t,n;
ll d,x[maxn];
ll dis[maxn][maxn];
ll cnt[maxn][maxn];
ll to[maxn][maxn];
void init()
{
    for(int i=1;i<=n;++i)
        for(int j=1;j<=n;++j)
            dis[i][j]=inf,cnt[i][j]=0,to[i][j]=0; 
}
int main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>c>>t;
    while(t--)
    {
        cin>>n>>d;
        init();
        for(int i=1;i<=n;++i)
            cin>>x[i];
        for(int i=1;i<=n;++i)
        {
            for(int j=1;j<i;++j)
            {
                if(abs(x[i]-x[j])<=d)
                    dis[i][j]=dis[j][i]=1,cnt[i][j]=cnt[j][i]=1;
            }
        }
        for(int i=1;i<=n;++i)   
            dis[i][i]=0;
        for(int k=1;k<=n;++k)
        {
            for(int i=1;i<=n;++i)
            {
                for(int j=1;j<=n;++j)
                {
                    if(dis[i][j]>dis[i][k]+dis[k][j])
                    {
                        dis[i][j]=dis[i][k]+dis[k][j];
                        cnt[i][j]=cnt[i][k]*cnt[k][j];
                    }
                    else if(dis[i][j]==dis[i][k]+dis[k][j])
                        cnt[i][j]+=cnt[i][k]*cnt[k][j];
                }
            }
        }
        ll ans=0;
        for(int i=1;i<=n;++i)
            for(int j=1;j<i;++j)
                if(cnt[i][j]==2)
                    ans++;
        cout<<ans<<"\n";
    }
    return 0;
}