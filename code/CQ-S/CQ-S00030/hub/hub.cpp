#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
static const int INF=1000000000;
int n; vector<vector<int>> adj;
vector<int> stamp, par_, order_, h_, inc_, U_;
int curstamp=0;
int R;

int gcomp(const vector<int>& nodes, int rt){
    ++curstamp;
    for(int v: nodes) stamp[v]=curstamp;
    order_.clear();
    for(int v: nodes) par_[v]=-2;
    par_[rt]=-1;
    vector<int> st; st.push_back(rt);
    while(!st.empty()){
        int a=st.back(); st.pop_back();
        order_.push_back(a);
        for(int b: adj[a]) if(stamp[b]==curstamp && par_[b]==-2){ par_[b]=a; st.push_back(b); }
    }
    for(int idx=(int)order_.size()-1; idx>=0; idx--){
        int a=order_[idx];
        int mx=0; long long tot=1;
        for(int b: adj[a]) if(stamp[b]==curstamp && par_[b]==a){
            if(1+h_[b]>mx) mx=1+h_[b];
            long long add = (h_[b]<=R-1)?0:(long long)INF;
            if(inc_[b]<add) add=inc_[b];
            tot+=add; if(tot>INF) tot=INF;
        }
        h_[a]=mx; inc_[a]=(int)tot;
    }
    U_[rt]=-1;
    for(int idx=0; idx<(int)order_.size(); idx++){
        int a=order_[idx];
        int best1=-1,best2=-1;
        for(int b: adj[a]) if(stamp[b]==curstamp && par_[b]==a){ int val=1+h_[b]; if(val>best1){best2=best1;best1=val;} else if(val>best2) best2=val; }
        for(int b: adj[a]) if(stamp[b]==curstamp && par_[b]==a){
            int val=1+h_[b];
            int sib=(val==best1)?best2:best1;
            int cand=U_[a];
            if(sib>cand) cand=sib;
            if(0>cand) cand=0;
            U_[b]=1+cand;
        }
    }
    int best=INF;
    for(int a: order_) if(U_[a]<=R && inc_[a]<best) best=inc_[a];
    return best;
}

int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);

    int c,t;
    if(fscanf(fi,"%d %d",&c,&t)!=2){ fclose(fi); fclose(fo); return 0; }
    while(t--){
        int k;
        if(fscanf(fi,"%d %d",&n,&k)!=2) break;
        adj.assign(n+1, vector<int>());
        vector<pair<int,int>> edges;
        for(int i=0;i<n-1;i++){ int u,v; fscanf(fi,"%d %d",&u,&v); adj[u].push_back(v); adj[v].push_back(u); edges.push_back({u,v}); }
        stamp.assign(n+1,0); par_.assign(n+1,-2); h_.assign(n+1,0); inc_.assign(n+1,0); U_.assign(n+1,0);
        curstamp=0;
        vector<int> allnodes(n); for(int i=0;i<n;i++) allnodes[i]=i+1;
        // binary search R in [0,n]
        int lo=0, hi=n, ansR=n;
        while(lo<=hi){
            R=(lo+hi)/2;
            int f=gcomp(allnodes,1);
            // 2-block
            vector<int> mark(n+1,0);
            for(auto &e: edges){
                int u=e.first,v=e.second;
                // component of u avoiding v
                vector<int> X,Y;
                { ++curstamp; vector<int> st; st.push_back(u); stamp[u]=curstamp; X.push_back(u);
                  while(!st.empty()){ int a=st.back(); st.pop_back(); for(int b: adj[a]) if(b!=v && stamp[b]!=curstamp){ stamp[b]=curstamp; st.push_back(b); X.push_back(b);} } }
                { int save=curstamp; ++curstamp; vector<int> st; st.push_back(v); stamp[v]=curstamp; Y.push_back(v);
                  while(!st.empty()){ int a=st.back(); st.pop_back(); for(int b: adj[a]) if(b!=u && stamp[b]!=curstamp){ stamp[b]=curstamp; st.push_back(b); Y.push_back(b);} } (void)save; }
                int gx=gcomp(X,u), gy=gcomp(Y,v);
                long long s=(long long)gx+gy; if(s<f) f=(int)min<long long>(s,INF);
            }
            if(f<=k){ ansR=R; hi=R-1; } else lo=R+1;
        }
        fprintf(fo,"%d\n",ansR);
    }
    fclose(fi); fclose(fo);
    return 0;
}

