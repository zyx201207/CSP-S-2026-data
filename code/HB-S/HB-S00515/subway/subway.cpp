#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
const long long inf=0x3f3f3f3f3f3f3f3f;
long long w[N];
typedef pair<long long,int> PII;
vector<PII> G[N];
long long dis[N];

void dij(int s){
    memset(dis,0x3f,sizeof(dis));
    dis[s]=0;
    priority_queue<PII,vector<PII>,greater<PII>> q;
    q.push({0,s});
    while(!q.empty()){
        PII t=q.top();
        q.pop();
        long long d=t.first;
        int u=t.second;
        if(d>dis[u]){
            continue;
        }
        for(PII y:G[u]){
            int v=y.second;
            long long w=y.first;
            if(dis[v]>dis[u]+w){
                dis[v]=dis[u]+w;
                q.push({dis[v],v});
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    int c,n,m,d,q;
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++){
        cin>>w[i];
        /*
        G[0].push_back({w,i});
        G[i].push_back({w,0});
        */
    }
    int cnt=m;
    for(int i=1;i<=n;i++){
        int k;
        cin>>k;
        for(int j=1;j<=k;j++){
            int dot;
            long long t;
            cin>>dot>>t;
            cnt++;
            G[cnt].push_back({t,dot});
            G[dot].push_back({t,cnt});
            if(j!=1){
                G[cnt-1].push_back({0,cnt});
                G[cnt].push_back({0,cnt-1});
            }
        }
    }
    while(q--){
        int x,y;
        cin>>x>>y;
        dij(x);
        long long ans=dis[y]+w[x]+w[y];
        cout<<ans<<'\n';
    }


    return 0;
}