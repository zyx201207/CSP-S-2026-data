#include <bits/stdc++.h>
using namespace std;
constexpr int N = 5e5+710;
struct pii {
    int v,t;
    pii(int v = 0,int t = 0)
        :v(v),t(t){}
    bool operator<(pii o) const{
        return t<o.t;
    }
    bool operator>(pii o) const{
        return t>o.t;
    }
};

struct s1 {
    int v,t,prt;
    s1(int v = 0,int t = 0,int prt = -1)
        :v(v),t(t),prt(prt){}
    bool operator<(s1 o) const{
        return t<o.t;
    }
    bool operator>(s1 o) const{
        return t>o.t;
    }
};
int c,m,n,d,q;
int w[N];
vector<pii> G[N];

int len(int a,int b){
    priority_queue<s1,vector<s1>,greater<s1>> q;
    q.push({a,0,-1});
    while(!q.empty()){
        s1 f = q.top();
        q.pop();
        if(f.v==b)
            return f.t;
        for(pii e : G[f.v]){
            if(e.v == f.prt)
                continue;
            q.push({e.v,e.t+f.t,f.v});
        }
    }
    return 0;
}

int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;++i){
        cin>>w[i];
    }
    int v,t,k;
    for(int i=1;i<=n;++i){
        cin>>k;
        for(int j = 0;j<k;++j){
            cin>>v>>t;
            G[m+i].push_back({v,t});
            G[v].push_back({m+i,t});
        }
    }
    int a,b;
    for(int i=1;i<=q;++i){
        cin>>a>>b;
        cout<<len(a,b)+w[a]+w[b]<<"\n";
    }
    return 0;
}
