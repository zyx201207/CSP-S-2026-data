#include<bits/stdc++.h>
using namespace std;
int w[100005];
int t[10005][10005];
int k[10005];
bool vis[10005][10005];
int c, n, m, d, q
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin >>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++){
        cin >> w[i];
    }
    for(int i=1;i<=n;i++){
        cin >> k[i];
        for(int j=1;j<=k[i];j++){
            int station;
            cin>>station;
            cin >> t[i][station];//line i
            vis[i][station]=1;
        }
    }
   
    while(q--){
        int from,to;
        cin >> from >> to;
        int minintime=INT_MAX;
        bool contiflag=0;
        for(int i=1;i<=n;i++){
                bool flaga=0,flagb=0;
            for(int j=1;j<=k[i];j++){
                if(vis[i][from]){
                    flaga=1;
                }
                if(vis[i][to]){
                    flagb=1;
                }
            }
             if(c>=12&&c<=19){
                if(flaga&&flagb){
                minintime=min(minintime,w[from]+w[to]+t[i][from]+t[i][to]);
                }
                cout <<< minintime<<endl;
                contiflag=1;
                break;
            }
            if(flaga&&flagb){
                minintime=min(minintime,w[from]+w[to]+t[i][from]+t[i][to]);
                cout <<minintime<<endl;
                contiflag=1;
            }
        }
        if(contiflag){
            continue;
        }
    }
    return 0;
}
