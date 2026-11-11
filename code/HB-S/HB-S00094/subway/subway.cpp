#include<bits/stdc++.h>
using namespace std;
#define int long long
#define PII pair<int,int>
#define X first
#define Y second
const int N=505,M=5e5+5,MAXN=M*2+N,INF=1e18;
int c,n,m,d,q,idx;
map<int,vector<PII>>e;
int tai[M],kou[M],dis[MAXN];
void init(){
    for(int i=1;i<=idx;i++)dis[i]=INF;
}
signed main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>c>>n>>m>>d>>q;
    for(int i=1,w;i<=m;i++){
        cin>>w;
        e[++idx].push_back({++idx,w});
        kou[i]=idx-1;
        e[idx].push_back({idx-1,w});
        tai[i]=idx;
    }
    for(int i=1,k;i<=n;i++){
        cin>>k;
        int id=++idx;
        for(int j=1,v,w;j<=k;j++){
            cin>>v>>w;
            e[id].push_back({tai[v],w});
            e[tai[v]].push_back({id,w});
        }
    }
    while(q--){
        int s,t;cin>>s>>t;
        int ids=kou[s],idt=kou[t];
        init();
        static priority_queue<PII,vector<PII>,greater<PII>>que;
        dis[ids]=0;
        que.push({0,ids});
        while(!que.empty()){
            PII six=que.top();que.pop();
            int u=six.Y;
            for(PII seven:e[u]){
                int v=seven.X,disv=seven.Y;
                if(dis[u]+disv<dis[v]){
                    dis[v]=dis[u]+disv;
                    que.push({dis[v],v});
                }
            }
        }
        cout<<dis[idt]<<"\n";
    }
    return 0;
}