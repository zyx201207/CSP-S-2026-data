#include <bits/stdc++.h>
using namespace std;
int c,n,m,q,d,w[500005],k[505],g[5003][5003],ti[5003][5003],dis[5003][5003];
struct node{
    int a,t;
};
vector<vector<node>> vec(505);
void floyd(){
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
            }
        }
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++){
        cin>>w[i];
    }
    for(int i=1;i<=n;i++){
        cin>>k[i];
        for(int j=1;j<=k[i];j++){
            int a,t;
            cin>>a>>t;
            ti[i][a]=t;
            vec[i].push_back({a,t});
            
        }
    }
    memset(g,0x3f,sizeof(g));
    memset(dis,0x3f,sizeof(dis));
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            for(int ii=0;ii<vec[i].size();ii++){
                for(int jj=0;jj<vec[j].size();jj++){
                    if(vec[i][ii].a==vec[j][jj].a){
                        g[i][j]=min(g[i][j],vec[i][ii].t+vec[j][jj].t);
                        g[j][i]=g[i][j];
                    }
                }
            }
        }
    }
    for(int i=1;i<=n;i++){
        g[i][i]=0;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            dis[i][j]=dis[j][i]=g[i][j];
        }
    }
    // for(int i=1;i<=n;i++){
    //     for(int j=1;j<=n;j++){
    //         cout<<g[i][j]<<' ';
    //     }
    //     cout<<endl;
    // }
    // cout<<endl;
    floyd();
    // for(int i=1;i<=n;i++){
    //     for(int j=1;j<=n;j++){
    //         cout<<dis[i][j]<<' ';
    //     }
    //     cout<<endl;
    // }
    // cout<<endl;
    while(q--){
        int x,y;
        cin>>x>>y;
        vector<int> xx,yy;
        for(int i=1;i<=n;i++){
            for(int ii=0;ii<vec[i].size();ii++){
                if(vec[i][ii].a==x){
                    xx.push_back(i);
                }
                if(vec[i][ii].a==y){
                    yy.push_back(i);
                }
            }
        }
        // for(int i=0;i<xx.size();i++){
        //     cout<<xx[i]<<' ';
        // }
        // cout<<endl;
        // for(int i=0;i<yy.size();i++){
        //     cout<<yy[i]<<' ';

        // }
        // cout<<endl;
        int ans=0x3f3f3f3f,l,r;
        for(int i=0;i<xx.size();i++){
            for(int j=0;j<yy.size();j++){
                if(ans>dis[xx[i]][yy[i]]){
                    ans=dis[xx[i]][yy[j]];
                    l=xx[i],r=yy[j];
                }
            }
        }
        // cout<<endl<<ti[l][x]<<' '<<ti[r][y]<<endl;
        cout<<ans+w[x]+w[y]+ti[l][x]+ti[r][y]<<endl;
    }
    return 0;
}