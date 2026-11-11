#include<bits/stdc++.h>
using namespace std;
const int INF=1e9;
int c,n,m,d,q;
int a[510][510],t[510][510],w[510];
struct Node{
    int point,cost;
};
vector<Node>e[510];
vector<int>pd[510];
//-------------------------------------------------
int diji(int start,int end){
    int dj[510][510];
    for(int i=0;i<=m;i++){
        for(int j=0;j<=m;j++){
        dj[0][i]=INF;
        }
    }
    dj[0][start]=0;
    for(int i=1;i<=m;i++){
        for(int j=1;j<=m;j++){
            for(auto u:e[j]){
                dj[i][u.point]=min(dj[i-1][u.point],dj[i-1][j]+u.cost);
                
            }
            if(dj[i][j]==0 && j!=start)dj[i][j]=min(dj[i-1][j],INF);
            //cout<<dj[i][j]<<' ';
        }
        //cout<<'\n';
    }
    return dj[m][end];
}

//-------------------------------------------------
int main(){
    freopen("subway.out","w",stdout);
    freopen("subway.in","r",stdin);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++)cin>>w[i];
    for(int i=1;i<=n;i++){
        int k;
        cin>>k;
        for(int j=1;j<=k;j++){
            int time;
            cin>>a[i][j]>>time;
            t[a[i][j]][i]=time;
            pd[a[i][j]].push_back(i);
            //cout<<a[i][j]<<' '<<time<<'\n';
        }
    }
//---------------------------------------------------
    for(int i=1;i<=m;i++){
        if(pd[i].size()<=1)continue;
        for(int j=0;j+1<pd[i].size();j++){
            e[pd[i][j]].push_back({pd[i][j+1],t[i][pd[i][j]]+t[i][pd[i][j+1]]});
            e[pd[i][j+1]].push_back({pd[i][j],t[i][pd[i][j]]+t[i][pd[i][j+1]]});

        }
    }
//----------------------------------------------------
    while(q--){
        int st,ed,ans[510][510];
        for(int i=0;i<=m;i++)
            for(int j=0;j<=m;j++)ans[i][j]=INF;
        cin>>st>>ed;
        for(int i:pd[st]){
            for(int j:pd[ed]){
                ans[i][j]=w[st]+w[ed]+t[st][i]+t[ed][j]+diji(i,j);
                //cout<<i<<' '<<j<<' '<<w[st]<<' '<<w[ed]<<' '<<t[st][i]<<' '<<t[ed][j]<<' '<<diji(i,j)<<'\n';
            }
        }

        int finalans=INF;
        for(int i=0;i<=m;i++)
            for(int j=0;j<=m;j++)finalans=min(finalans,ans[i][j]);
        cout<<finalans<<'\n';
    }
    return 0;
}