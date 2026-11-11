#include<bits/stdc++.h>
using namespace std;
#define int long long
#define pb push_back
#define mp make_pair
constexpr int N=(1<<21)+7;

int n,m,C,d,q,w[N];

vector<vector<pair<int,int>>>G;
vector<vector<int>>a,t;
vector<int>P;
map<pair<int,int>,int>mp_ans;

using pii=pair<int,int>;

inline int solve_ans1(int sx,int sy){
    int i,j,k,l,r,x,y,z;
    int ans=w[sx]+w[sy];
    priority_queue<pii,vector<pii>,greater<pii>>Q;
    vector<int>dis;
    bitset<N>vis;
    vis.reset();
    dis.resize((n+2)*(m+2)+507);
    for(i=1;i<=(n+2)*(m+2);++i){
        if(i==sx+n*m) dis[i]=0;
        else dis[i]=4e18;
    }
    Q.push({ 0,n*m+sx });
    for(;!Q.empty();){
        int ww=Q.top().first,u=Q.top().second;
        Q.pop();
        for(int i=0;i<G[u].size();++i){
            int v=G[u][i].first,e=G[u][i].second;
            int abc=dis[v];
            if(abc>ww+e){
                dis[v]=ww+e;
                Q.push({ dis[v],v });
            }
        }
    }// cerr<<dis[7]<<endl;
    return ans+dis[n*m+sy];
}
inline void solve1(){
    int i,j,k,l,r,x,y,z;
    a.resize(n+2),t.resize(n+2);
    G.resize((n+2)*(m+2)+507);
    P.resize(n*m+7);
    for(i=1;i<=n*m+1;++i) P[i]=-1;
    for(i=1;i<=n;++i){
        cin>>k;
        int idx=(i-1)*m;
        for(j=1;j<=k;++j){
            cin>>x>>y;
            a[i].pb(x),t[i].pb(y);
            P[x+idx]=y;
        }
        for(j=0;j<a[i].size();++j){
            G[a[i][j]+idx].pb(mp((n+1)*m+i,0));
            G[(n+1)*m+i].pb(mp(a[i][j]+idx,0));
            G[a[i][j]+idx].pb(mp(n*m+a[i][j],t[i][j]));
            G[n*m+a[i][j]].pb(mp(a[i][j]+idx,t[i][j]));
        }
    }
    for(i=1;i<=q;++i){
        cin>>x>>y;
        if(!mp_ans[{ x,y }]){
            mp_ans[{ x,y }]=solve_ans1(x,y);
            cout<<mp_ans[{ x,y }]<<endl;
        }else{
            cout<<mp_ans[{ x,y }]<<endl;
        }
    }
    return ;
}
// #define LOCAL_TEST abcdg
signed main(){
    ios::sync_with_stdio(false),cin.tie(0);

    int i,j,k,l,r,x,y,z;

    #ifndef LOCAL_TEST
        freopen("subway.in","r",stdin);
        freopen("subway.out","w",stdout);
    #endif

    cin>>C>>n>>m>>d>>q;
    for(i=1;i<=m;++i) cin>>w[i];
    solve1();
    return 0;
}
/*
for(i=1;i<=n;++i){
        cin>>k;
        int idn=(i-1)*m;
        //fenceng
        for(j=1;j<=k;++j){
            cin>>x>>y;
            a[i].pb(x),t[i].pb(y);
            P[x+idn]=y;
        }
        for(j=0;j<a[i].size()-1;++j){
            G[a[i][j]+idn].pb(mp(a[i][j+1]+idn,0));
            // connect the same railway road to each other,
            // the connect model is a round:
            // a->b->c->d->...->m->n->a
        }G[a[i][a[i].size()-1]+idn].pb(mp(a[i][0]+idn,0));
        // connect the last point and the first point
        for(j=0;j<a[i].size();++j){
            G[a[i][j]+idn].pb(mp(n*m+a[i][j],t[i][j]));
            G[n*m+a[i][j]].pb(mp(a[i][j]+idn,t[i][j]));
        }
        // connect to super point
    }
*/