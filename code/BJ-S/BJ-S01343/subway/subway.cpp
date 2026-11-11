#include<bits/stdc++.h>
using namespace std;
int w[500005];
int t[500005][505];
struct Node{
    int id;
    int time;
};
vector<Node> ve1[500005];
int t1[500005][505];
signed main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    memset(t,-1,sizeof(t));
    int c,n,m,d,q;
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++){
        cin>>w[i];
    }
    for(int i=1;i<=n;i++){
        int k;
        cin>>k;
        while(k--){
            int a,t;
            cin>>a>>t;
            t1[a][i]=t;
            ve1[a].push_back({i,t});
        }
    }
    for(int i=1;i<=502;i++){
        for(int j=1;j<=502;j++){
            t[i][j]=-1;
        }
    }
    for(int i=1;i<=m;i++){
        for(int j=0;j<ve1[i].size();j++){
            for(int k=j+1;k<ve1[i].size();k++){
                int jid=ve1[i][j].id;
                int kid=ve1[i][k].id;
                int ktim=ve1[i][k].time;
                int jtim=ve1[i][j].time;
                if(t[i][j]==-1)
                    t[kid][jid]=t[jid][kid]=ktim+jtim;
                else{
                    t[kid][jid]=t[jid][kid]=min(ktim+jtim,t[jid][kid]);
                }

            }
        }
    }
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            for(int k=i+1;k<=n;k++){
                if(i==j||j==k) continue;
                if(i==k){
                    t[i][k]=0;
                    continue;
                }
                if(t[i][j]!=-1&&t[j][k]!=-1){
                    if(t[i][k]==-1) {
                        t[k][i]=t[i][k]=t[i][j]+t[j][k];
                    }
                    else {
                        t[k][i]=t[i][k]=min(t[i][j]+t[j][k],t[i][k]);
                    }
                }
            }

    while(q--){
        int b,e;
        cin>>b>>e;
        int ans=1000000000;
        for(int j=0;j<ve1[b].size();j++){
            for(int k=0;k<ve1[e].size();k++){
                if(t[ve1[b][j].id][ve1[e][k].id]!=-1){
                    int cnt=t[ve1[b][j].id][ve1[e][k].id];
                    ans=min(ans,cnt+t1[b][ve1[b][j].id]+t1[e][ve1[e][k].id]);
                }

            }
        }
        cout<<ans+w[b]+w[e]<<'\n';
    }
    return 0;
}
