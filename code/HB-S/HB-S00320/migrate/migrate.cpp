#include<bits/stdc++.h>
using namespace std;
#define LL long long
#define N 5005
#define INF 1e9
int c,t,n,d;
int isl[N],di[N],vis[N],cnt[N][N];
vector<int> mp[N];
void dijkstra(LL x){
    for(LL i=1;i<=n;i++){
        di[i]=INF;
    }
    memset(vis,0,sizeof(vis));
    di[x]=0;
    priority_queue<pair<int,LL>> pq;
    pq.push(make_pair(0,x));
    while(!pq.empty()){
        LL u=pq.top().second;
        //cout<<u<<endl;
        pq.pop();
        if(vis[u])continue;
        vis[u]=1;
        for(LL i=0;i<mp[u].size();i++){
            LL v=mp[u][i];
            if(di[u]+1<di[v]){
                cnt[u][v]=0;
                di[v]=di[u]+1;
                pq.push(make_pair(-di[v],v));
            }else if(di[u]+1==di[v]){
                cnt[u][v]++;
            }
        }
    }
}
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    while(t--){
        cin>>n>>d;
        for(int i=1;i<=n;i++){
            cin>>isl[i];
        }
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                if(isl[j]-isl[i]<=d){
                    mp[i].push_back(j);
                }else{
                    break;
                }
            }
        }
        int ans=0;
        dijkstra(1);
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                if(cnt[i][j]==1){
                    //cout<<i<<" "<<j<<endl;
                    ans++;
                }
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
