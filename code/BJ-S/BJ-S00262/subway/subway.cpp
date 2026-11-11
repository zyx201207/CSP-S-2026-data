#include<bits/stdc++.h>
using namespace std;
int t,n,m,d,q,ans;
int totst[501]
vector<int> line[501];
int out[500005];
vector<pair<int,int> > st[500005];
bool vis[500005]
struct pos{
    int posi,faline,dis;
};
void solve(int x,int y){
    queue<pos > q;
    q.push({x,0,0});
    vis[x]=true;
    while(!q.empty()){
        pos position=q.front();
        q.pop();
        int posi=position.posi,faline=position.faline,dis=position.dis;
        for(i=0;i<st[posi].size(),i++){
            if(i=faline)
            int ln=st[posi][i].first,distance=st[posi][i].second;
            for(int j=0;j<line[ln].size(),j++){
                if(!vis[j]){
                    
                }
            }
        }
    }
}
int main(){
    cin>>t>>n>>m>>d>>q;
    for(int i=1;i<=m;i++){
        cin>>out[i];
    }
    for(int i=1;i<=n;i++){
        cin>>totst[i];
        for(int j=1;j<=totst[i];j++){
            int station,tim;
            cin>>station>>tim;
            line[i].push_back(station);
            st[station].push_back({i,tim});
        }
    }
    for(int i=1;i<=q;i++){
        int x,y;
        cin>>x>>y;
        solve(x,y);
    }
}
