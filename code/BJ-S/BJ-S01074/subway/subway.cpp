#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=1e6,INF=0x3f3f3f3f;
typedef pair<ll,ll> PII;

ll c,n,m,d,Q;
ll w[N],k,a[N],t[N];
ll S,T;
ll dist[N];
bool st[N];

vector<PII> mp[N];
priority_queue<PII,vector<PII>,greater<PII> > q;

void dj(ll x){
    for(int i=1;i<=6e5;i++){
        dist[i]=INF;
        st[i]=false;
    }
    dist[x]=0;
    q.push({0,x});
    while(q.size()){
        auto [t1,t2]=q.top();
        q.pop();
        if(st[t2]) continue;
        st[t2]=true;
        //cout<<t2<<' '<<t1<<"\n";
        for(auto [i,j]:mp[t2]){
            if(dist[j]>dist[t2]+i){
                dist[j]=dist[t2]+i;
                q.push({dist[j],j});
            }
        }
    }
    return ;
}
ll idx;
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>Q;
    idx=m;
    for(int i=1;i<=m;i++){
        cin>>w[i];
    }
    for(int i=1;i<=n;i++){
        cin>>k;
        for(int j=1;j<=k;j++){
            cin>>a[j]>>t[j];
        }
        idx++;
        for(int j=1;j<=k;j++){
            mp[a[j]].push_back({t[j],idx});
            mp[idx].push_back({t[j],a[j]});
        }
    }
    while(Q--){
        cin>>S>>T;
        dj(S);
        //cout<<"\n";
        cout<<dist[T]+w[S]+w[T]<<"\n";
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
