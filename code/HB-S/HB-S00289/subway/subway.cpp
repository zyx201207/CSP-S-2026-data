#include <bits/stdc++.h>

using namespace std;
#define int long long
struct node{
    int to;
    int cost;
};
const int len=500005;
int w[500005];
int dis[505][505];
vector<vector<node>> pass;
signed main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int c;cin>>c;
    int n,m,d,q;cin>>n>>m>>d>>q;
    pass.resize(m+1);
    for(int i=1;i<=m;i++)pass.reserve(d+5);
    for(int i=1;i<=500;i++){
        for(int j=1;j<=500;j++){
            if(i==j)dis[i][j]=0;
            else dis[i][j]=LLONG_MAX;
        }
    }
    for(int i=1;i<=m;i++){
        cin>>w[i];
    }
    int temp,a,t;
    for(int i=1;i<=n;i++){
        cin>>temp;
        for(int j=1;j<=temp;j++){
            cin>>a>>t;
            pass[a].push_back({i,t});
        }
    }
    for(int i=1;i<=m;i++){
        for(int j=0;j<pass[i].size();j++){
            for(int k=j+1;k<pass[i].size();k++){
                int from=pass[i][j].to;int go=pass[i][k].to;
                //cout<<from<<" "<<go<<endl;
                dis[from][go]=min(dis[from][go],pass[i][j].cost+pass[i][k].cost);
                dis[go][from]=min(dis[go][from],pass[i][j].cost+pass[i][k].cost);

            }
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            for(int k=1;k<=n;k++){
                if(dis[i][k]!=LLONG_MAX&&dis[k][j]!=LLONG_MAX)
                dis[j][i]=dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
            }
        }
    }
    //for(int i=1;i<=n;i++){
    //    for(int j=1;j<=n;j++){
    //        cout<<dis[i][j]<<" ";
    //    }
    //    cout<<endl;
    //}
    int s,e;
    int u=1;
    while(q--){
        cin>>s>>e;
        int ans=LLONG_MAX;
        for(int i=0;i<pass[s].size();i++){
            for(int j=0;j<pass[e].size();j++){
                ans=min(ans,w[s]+pass[s][i].cost+dis[pass[s][i].to][pass[e][j].to]+pass[e][j].cost+w[e]);
            }
        }
        cout<<u<<" "<<ans<<"\n";
        u++;
    }
}
