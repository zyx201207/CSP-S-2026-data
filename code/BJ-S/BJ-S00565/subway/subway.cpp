#include<bits/stdc++.h>
using namespace std;
#define int long long
#define PII pair<int,int>
const int N=5e5+5,M=3e7+5;
int w[N],p[N],kk[N],S[M],dis[M];
vector<PII> G[M];

void Dijkstra(int s,int t){
    priority_queue<PII,vector<PII >,greater<PII > > q;
    q.push(make_pair(s,0));
    memset(dis,0x3f,sizeof(dis));
    memset(S,0,sizeof(S));
    dis[s]=0;
    while(!q.empty()){
        int u=q.top().first;
        q.pop();
        if(S[u]) continue;
        S[u]=1;
        for(auto [v,w]:G[u]){
                //cout<<u<<' '<<v<<endl;
            if(S[v]) continue;
            if(dis[v]>dis[u]+w){
                dis[v]=dis[u]+w;
                q.push(make_pair(v,dis[v]));
            }
        }
    }
    return ;
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    freopen("subway.in","r",stdin);

    freopen("subway.out","w",stdout);
    int c,n,m,d,q,k,s,t,a,b;
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;++i) cin>>w[i];
    while(n--){
        cin>>k;
        for(int i=1;i<=k;++i){
            cin>>s>>t;
            kk[i]=s;
            ++p[s];
            G[s*22].push_back(make_pair(s*22+p[s],t));
            G[s*22+p[s]].push_back(make_pair(s*22,t));
        }
        for(int i=2;i<=k;++i){
            G[kk[i]*22+p[kk[i]]].push_back(make_pair((kk[i]-1)*22+p[kk[i]-1],0));
            G[(kk[i]-1)*22+p[kk[i]-1]].push_back(make_pair(kk[i]*22+p[kk[i]],0));
        }
    }
    while(q--){
        cin>>a>>b;
        Dijkstra(a*22,b*22);
        cout<<dis[b*22]+w[a]+w[b]<<endl;
        //cout<<"-----------------"<<endl;
    }
    return 0;
}
