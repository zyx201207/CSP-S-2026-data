#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
using namespace std;
ll c,T;
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>T;
    while(T--){
        ll n,d;
        cin>>n>>d;
        ll x[n+5];
        for(int i=1;i<=n;i++){
            cin>>x[i];
        }
        vector<ll> g[5005];
        for(int i=1;i<n;i++){
            for(int j=i+1;j<=n;j++){
                if(x[j]-x[i]>d)break;
                g[i].push_back(j);
            }
        }
        int dis[5005],cnt[5005],mn[5005];
        int ans=0;
        for(int i=1;i<=n;i++){
            queue<pii> q;
            for(int j=1;j<=n;j++) dis[j]=0,cnt[j]=0;
            q.push({i,0});
            while(!q.empty()){
                int u=q.front().first;
                int t=q.front().second;
                q.pop();
                for(int v:g[u]){
                    if(dis[v]==0||dis[v]==t+1){
                        cnt[v]++;
                    }
                    else continue;
                    if(dis[v]==0) dis[v]=t+1;
                    q.push({v,t+1});
                }
            }
            for(int j=i+1;j<=n;j++){
                if(cnt[j]==2){
                    ans++;
                }

            }
        }
        cout<<ans<<endl;

    }
    return 0;
}
