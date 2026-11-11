#include<bits/stdc++.h>
using namespace std;
struct node{
    long long x,y;
};
int c,n,m,d,q;
long long fl[501][501],w[500005],cnt[500005];
vector<node>e[500005];
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    memset(fl,0x3f,sizeof fl);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++)cin>>w[i],e[i].push_back({-1,114514});
    for(int i=1;i<=n;i++){
        int k;
        cin>>k;
        for(int j=1;j<=k;j++){
            int x,y;
            cin>>x>>y;
            e[x].push_back({i,y});
            cnt[x]++;
        }
    }
    for(int i=1;i<=m;i++){
        for(int j=1;j<=cnt[i];j++){
            for(int k=1;k<j;k++){
                fl[e[i][j].x][e[i][k].x]=min(fl[e[i][j].x][e[i][k].x],e[i][j].y+e[i][k].y);
                fl[e[i][k].x][e[i][j].x]=min(fl[e[i][k].x][e[i][j].x],e[i][j].y+e[i][k].y);
            }
        }
    }
    for(int i=1;i<=n;i++)fl[i][i]=0;
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                fl[i][j]=min(fl[i][j],fl[i][k]+fl[k][j]);
            }
        }
    }
    while(q--){
        int st,ed;
        long long ans=0x3f3f3f3f3f3f3f3f;
        cin>>st>>ed;
        for(int i=1;i<=cnt[st];i++){
            for(int j=1;j<=cnt[ed];j++){
                ans=min(ans,fl[e[st][i].x][e[ed][j].x]+e[st][i].y+e[ed][j].y);
                //cout<<e[st][i].x<<' '<<e[ed][j].x<<' '<<e[st][i].y<<' '<<e[ed][j].y<<'\n';
            }
        }
        cout<<ans+w[st]+w[ed]<<'\n';
    }
    return 0;
}
