#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
#define FOR(i,a,b) for(int i=(a),EEEE##i=(b); i<=EEEE##i; i++)
#define REV(i,a,b) for(int i=(a),EEEE##i=(b); i>=EEEE##i; i--)
#define endl '\n'
template<typename T>
void outval_(string s,int p,const T& t){cerr<<s.substr(p,s.size()-p)<<"="<<t<<endl;}
template<typename T,typename... Args>
void outval_(string s,int p,const T& t,const Args& ...rest){
    while(s[p]!=',') cerr<<s[p++]; cerr<<"="<<t<<"  ";
    outval_(s,p+1,rest...);
}
#define outval(...) outval_(#__VA_ARGS__,0,__VA_ARGS__)
#define outarr(aaa,beee,eddd)\
{cerr<<(#aaa)<<"= "; FOR(iii,beee,eddd) cerr<<'['<<iii<<']'<<'='<<aaa[iii]<<"  "; cerr<<endl;}
bool MBE;
const int N=505;
const int M=5e5+5;
const ll inf=1e15;
int C,n,m,d,q;
struct QWQ{
    int v; ll w;
};
vector<QWQ> bel[M];
ll W[M],dis[N][N];
bool MED;
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
//    freopen("/home/csp-s-2026/subway/subway7.in","r",stdin);
//    freopen("/home/csp-s-2026/subway/out.txt","w",stdout);
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin>>C>>n>>m>>d>>q;
    FOR(i,1,m) cin>>W[i];
    FOR(i,1,n){
        int k; cin>>k;
        FOR(j,1,k){
            int a; ll t; cin>>a>>t;
            bel[a].push_back((QWQ){i,t});
        }
    }
    FOR(i,1,n) FOR(j,1,n) dis[i][j]=inf;
    FOR(i,1,n) dis[i][i]=0;
    FOR(u,1,m){
        for(QWQ x:bel[u]){
            for(QWQ y:bel[u]){
                dis[x.v][y.v]=min(dis[x.v][y.v],x.w+y.w);
            }
        }
    }
    FOR(k,1,n) FOR(u,1,n) FOR(v,1,n)
        dis[u][v]=min(dis[u][v],dis[u][k]+dis[k][v]);
//    FOR(i,1,n) FOR(j,1,n) outval(i,j,dis[i][j]);
    while(q--){
        int u,v; cin>>u>>v;
        ll ans=inf;
        for(QWQ x:bel[u]){
            for(QWQ y:bel[v]){
//                outval(x.v,x.w,y.v,y.w,dis[x.v][y.v]);
                ans=min(ans,x.w+y.w+dis[x.v][y.v]);
            }
        }
        ans+=W[u]+W[v];
        cout<<ans<<endl;
    }
    cerr<<fixed<<setprecision(3)<<abs(&MBE-&MED)/1048576.0<<" MB"<<endl;
    return 0;
}
//Think twice, code once!!!
//luogu uid=923403, RP++
