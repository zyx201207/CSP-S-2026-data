#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll c,T,n,d,a[2000005],dis[505][505],cnt[505][505];
int main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>c>>T;
        while(T--)
        {
            memset(cnt,0,sizeof(cnt));
            cin>>n>>d;ll ans=0;
            for(int i=1;i<=n;i++)
                for(int j=1;j<=n;j++)
                    dis[i][j]=4e18;
            for(ll i=1;i<=n;i++)
                cin>>a[i];
            for(ll i=1;i<=n;i++)
            {
                dis[i][i]=0,cnt[i][i]=1;
                for(ll j=i+1;j<=n;j++)
                {
                    for(ll k=i;k<=j-1;k++)
                        if(a[j]-a[k]<=d)
                        {
                            if(dis[i][k]+1<dis[i][j]) dis[i][j]=dis[i][k]+1,cnt[i][j]=cnt[i][k];
                            else if(dis[i][k]+1==dis[i][j]) cnt[i][j]+=cnt[i][k];
                        }
                                    }
            }
            for(int i=1;i<=n;i++)
                for(int j=i+1;j<=n;j++)
                    if(cnt[i][j]==2)
                {
                ans++;
                }

            cout<<ans<<endl;
        }
    return 0;
}
