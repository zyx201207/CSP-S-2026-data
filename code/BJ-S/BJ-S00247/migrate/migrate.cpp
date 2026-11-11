#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
const ll INF=2e18+10;
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    int c,t;
    cin>>c>>t;
    while(t--){
        int n;
        ll d;
        cin>>n>>d;
        vector<ll> island(n+1,0);
        for(ll i=1;i<=n;i++){
            cin>>island[i];
        }
        vector<vector<ll>> dis(n+1,vector<ll>(n+1,INF));
        for(int i=1;i<=n;i++) dis[i][i]=0;
        for(int i=1;i<=n;i++){
                if(island[i]-island[i-1]<d){
                    dis[i-1][i]=island[i]-island[i-1];
                }
        }
        int ans=0;
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                int cnt=0;
                for(int k=i;k<=j;k++){
                    if(dis[i][k]!=INF&&dis[k][j]!=INF&&dis[i][k]<=d&&dis[k][j]<=d){
                        if(dis[i][j]>dis[i][k]+dis[k][j]){
                            dis[i][j]=dis[i][k]+dis[k][j];
                        }
                    }
                }
                if(cnt==2) ans++;
            }
        }
        for(int i=1;i<=n;i++){
            for(int j=i+2;j<=n;j++){
                int cnt=0;
                for(int k=i+1;k<=j-1;k++){
                    if(dis[i][k]!=INF&&dis[k][j]!=INF&&dis[i][k]<=d&&dis[k][j]<=d){
                        if(dis[i][j]==dis[i][k]+dis[k][j]){
                            cnt++;
                        }
                    }
                }
                if(cnt==2) ans++;
            }
        }
        cout<<ans<<'\n';
    }
    return 0;
}