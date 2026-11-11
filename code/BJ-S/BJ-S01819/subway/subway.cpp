#include<bits/stdc++.h>
using namespace std;
const int large = 1e3+4;
int c,n,m,d,q;
int tim_stod[large];
int tim_rtos[large];
int vis[large] = {0};
int conect[large];
struct wan{
    vector<int>next[large];

}p[large];
int ans = INT_MIN;
void bfs(int start,int walk,int ending,int type){
    vis[start] = 1;
    queue<int>bfsing;
    queue<int>phy;
    if(ending = start){
        ans = max(ans,walk);
    }
    else{
        for(int i=1;i<=n;i++){
            if(p[start].next[i].empty()) continue;
            else{
                for(int j=1;j<=p[start].next[i].size();j++){
                    bfsing.push(p[start].next[i][j]);
                    if(type == i)phy.push(-1);
                    else phy.push(i);
                }
            }
        }
        while(!bfsing.empty()){
            int kg = bfsing.front(),nt = phy.front();
            bfsing.pop();phy.pop();
            if(nt = -1) bfs(kg,walk,ending,type);
            else bfs(kg,walk+tim_rtos[type]+tim_rtos[nt],ending,nt);
            vis[kg] = 0;
        }
    }
    return ;
}
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin >>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++) cin >>tim_stod[i];
    for(int i=1;i<=n;i++){
        int k;cin >>k;
        for(int j=1;j<=k;j++){
            cin >>conect[j]>>tim_rtos[j];
            for(int o=j;o>=1;o--){
                p[conect[o]].next[i].push_back(conect[j]);
            }
        }
    }

    while(q--){
        int xi,yi;
        cin >>xi>>yi;
        for(int i=1;i<=n;i++){
            if(p[xi].next[i].empty()){
                continue;
            }
            else bfs(xi,0,yi,i);
        }
        cout <<ans+tim_stod[xi]+tim_stod[yi]<<endl;
    }
    return 0;
}
