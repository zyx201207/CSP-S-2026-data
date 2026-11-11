#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
ll d,x[2000005];
int cnt[5005],dis[5005];
void solve(){
    ll ans=0;
    for(int i=1;i<=n;i++){
        memset(dis,0x3f,sizeof(dis));
        dis[i]=0;
        cnt[i]=1;
        for(int j=i;j<=n;j++){
            int t=j+1;
            while(t<=n&&x[t]-x[j]<=d){
                if(dis[t]>dis[j]+1){
                    dis[t]=dis[j]+1;
                    cnt[t]=cnt[j];
                }else if(dis[t]==dis[j]+1){
                    cnt[t]+=cnt[j];
                }
                t++;
            }
        }
        for(int j=i;j<=n;j++){
            if(cnt[j]==2) ans++;
            cnt[j]=0;
        }
    }
    cout<<ans<<"\n";
}
int main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int c,t;
    cin>>c>>t;
    ios::sync_with_stdio(0);
    cin.tie(0);
    while(t--){
        cin>>n>>d;
        for(int i=1;i<=n;i++){
            cin>>x[i];
        }
        solve();
    }
    return 0;
}