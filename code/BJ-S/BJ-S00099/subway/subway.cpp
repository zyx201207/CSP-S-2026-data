#include<bits/stdc++.h>
using namespace std;
const long long oo=1e18;
long long w[500100];
long long k[500100];
bool vis[510];
int _,n,m,d,q;
struct E{
    int  v,w;
};
struct F{
    long long d,id;
    bool operator>(const F &a)const{
        return d>a.d;
    }
}dt[510];
vector<long long>a[510];
vector<E>stt[21];
vector<long long>t[510];
vector<E>e[510];
long long trans(int sub1,int sub2){
    memset(vis,0,sizeof(vis));
    if(sub1==sub2)return 0;
    priority_queue<F,vector<F>,greater<F>> q;
    for(int i=1;i<=n;i++){
        dt[i].id=i;
        dt[i].d=oo;
    }
    dt[sub1].d=0;
    q.push(dt[sub1]);
    for(int i=1;i<=n;i++){
        F tp;
        if(q.empty())break;
        while(!q.empty()){
            tp=q.top();
            q.pop();
            if(vis[tp.id]==0)break;
        }
        vis[tp.id]=1;
        for(auto &j:e[tp.id]){
            if(dt[tp.id].d+j.w<dt[j.v].d){
                dt[j.v].d=dt[tp.id].d+j.w;
                q.push(dt[j.v]);
            }
        }
    }
    return dt[sub2].d;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>_>>n>>m>>d>>q;
    for(int i=1;i<=m;i++){
        cin>>w[i];
    }
    for(int i=1;i<=n;i++){
        cin>>k[i];
        for(int j=1;j<=k[i];j++){
            int A,T;
            cin>>A>>T;
            t[i].push_back(T);
            a[i].push_back(A);
            stt[A].push_back({i,T});
        }
    }
    for(int i=1;i<=m;i++){
        if(stt[i].size()>1){
            for(int k=0;k<stt[i].size();k++){
                for(int j=0;j<k;j++){
                    e[stt[i][k].v].push_back({stt[i][j].v,stt[i][j].w+stt[i][k].w});
                    e[stt[i][j].v].push_back({stt[i][k].v,stt[i][j].w+stt[i][k].w});
        
                }
            }
        }
    }
    for(int i=1;i<=q;i++){
        int s,t;
        long long ans=oo;
        cin>>s>>t;
        for(auto &j:stt[s]){
            for(auto &k:stt[t]){
                ans=min(ans,w[s]+w[t]+j.w+k.w+trans(j.v,k.v));
            }
        }
        cout<<ans<<"\n";
    }
    return 0;
}