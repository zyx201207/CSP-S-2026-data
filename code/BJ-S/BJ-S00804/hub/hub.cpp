#include<bits/stdc++.h>
#define int long long
#define PC __builtin_popcountll
using namespace std;
const int N=2e6+7;
int n,k;
vector<int> E[N];
inline int Calcr(int S){
    static int Dis[N];
    for(int i=1;i<=n;i++)Dis[i]=-1;
    queue<int> q;
    for(int i=0;i<n;i++){
        if((S>>i)&1){
            // cout<<i+1<<" ";
            q.push(i+1),Dis[i+1]=0;
        }
    }
    // cout<<endl;
    while(!q.empty()){
        int u=q.front();q.pop();
        for(auto v:E[u]){
            if(Dis[v]==-1)Dis[v]=Dis[u]+1,q.push(v);
        }
    }
    int Rad=0;
    for(int i=1;i<=n;i++){
        Rad=max(Rad,Dis[i]);
    }
    // cout<<Rad<<endl;
    return Rad;
}
inline bool ChkLeg(int S){
    int Poi=k,Ed=0;;
    for(int i=0;i<n;i++){
        if((S>>i)&1){
            int u=i+1;
            for(auto v:E[u]){
                if((S>>v-1)&1)Ed++;
            }
        }
    }
    Ed>>=1;
    if(Poi-Ed<=2)return 1;
    else return 0;
}
inline void BF(){
    int Ans=n;
    for(int S=0;S<(1<<n);S++){
        // cout<<S<<endl;
        if(PC(S)!=k)continue;
        // cout<<"! "<<S<<endl;
        if(ChkLeg(S)){
            // cout<<"!! "<<S<<endl;
            Ans=min(Ans,Calcr(S));
        }
    }
    cout<<Ans<<endl;
}
inline void slv(){
    cin>>n>>k;
    for(int i=1;i<=n;i++)E[i].clear();
    for(int i=1;i<n;i++){
        int u,v;cin>>u>>v;
        E[u].push_back(v),E[v].push_back(u);
    }
    BF();
    return;
}
signed main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    int c,t;cin>>c>>t;
    while(t--)slv();
}