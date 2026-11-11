#include<bits/stdc++.h>
using namespace std;

int wm,xm,ym,xmh,ymh;
long long c,n,m,d,q,res=0x3f3f3f3f;
map<int,int> w;
vector<vector<pair<int,int>>> g;
void bfs(long long auxb,long long auxe){
        long long laux,flaux;
        queue<pair<long long,long long>> bfspn;
        bfspn.push({0,auxe});
        laux=bfspn.back().second;
        flaux=bfspn.back().first;
        for(long long i=0;i<g[laux].size();i++){
                bfspn.push({flaux+g[laux][i].first,g[laux][i].second});
        }
        bfspn.pop();
        while(!bfspn.empty()){
                laux=bfspn.back().second;
                flaux=bfspn.back().first;
                for(long long i=0;i<g[laux].size();i++){
                        bfspn.push({flaux+g[laux][i].first,g[laux][i].second});
                }
                res=min(res,bfspn.back().first);
                bfspn.pop();
        }
        res+=w[auxb]+w[auxe];
        cout<<res<<"\n";
}

int main(){
        freopen("subway.in","r",stdin);
        freopen("subway.ans","w",stdout);
    cin>>c>>n>>m>>d>>q;
    g.resize(m+1);
    for(long long i=1;i<=m;i++){
            cin>>wm;
            w[i]=wm;
    }
    for(long long i=1;i<=n;i++){
            cin>>wm;
            cin>>xmh>>ymh;
            for(int j=1;j<=(wm-1);j++){
                cin>>xm>>ym;
                g[xm].push_back({xmh,ymh+ym});
            }
    }
    for(int i=0;i<q;i++){
        long long auxb,auxe;
        cin>>auxb>>auxe;
        bfs(auxb,auxe);
    }
}