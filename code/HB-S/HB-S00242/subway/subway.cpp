#include<bits/stdc++.h>
#define pii pair<int,int>
#define inf 0x3f3f3f3f
using namespace std;
const int maxn=5e5+50;
struct node{
    int x;
    int in;
    vector<pii>w;
}a[maxn];
struct state{
    int x;
    int time;
    int line;
};
vector<pii>to[maxn];
bool vis[maxn];
int c,n,m,d,q;

int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++){
        cin>>a[i].in;
    }
    for(int i=1;i<=n;i++){
        int k;
        cin>>k;
        for(int j=1;j<=k;j++){
            int rech,time;
            cin>>rech>>time;
            to[i].push_back({rech,time});
            a[rech].w.push_back({i,time});
        }
    }
    while(q--){
        int s,e;
        memset(vis,0,sizeof(vis));
        cin>>s>>e;
        vis[s]=1;
        queue<state>q;
        q.push({s,0,0});
        while(!q.empty()){
            state g=q.front();
            q.pop();
            if(g.x==e){
                cout<<g.time+a[s].in+a[e].in<<endl;
                break;
            }
            for(pii f:a[g.x].w){
                if(g.line==0){
                    g.line=f.first;
                    g.time=g.time+a[s].w[0].second;
                }
                if(g.line==f.first){
                    for(int i=0;i<to[g.line].size();i++){
                        if(to[g.line][i].first==g.x){
                            if(i!=0){
                                q.push({to[g.line][i-1].first,g.time,g.line});
                            }
                            if(i!=to[g.line].size()){
                                q.push({to[g.line][i+1].first,g.time,g.line});
                            }
                        }
                    }
                }
                else{
                    for(int i=0;i<to[g.line].size();i++){
                        if(to[g.line][i].first==g.x){
                            for(int j=0;j<to[g.line].size();j++){
                                if(to[g.line][j].first==g.x){
                                    if(i!=0){
                                        q.push({to[g.line][i-1].first,g.time+to[g.line][i].second+to[f.first][j].second,f.first});
                                    }
                                    if(i!=to[g.line].size()){
                                        q.push({to[g.line][i+1].first,g.time+to[g.line][i].second+to[f.first][j].second,f.first});
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    return 0;
}