#include <bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
int w[500010];
vector<pair<int,int> > g[500010];
int a[5100][5100];
int dis[5100][5100];
int t[5100][5100];
int k[500010];
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0);cin.tie(0);
    cin>>c>>m>>n>>d>>q;
    for(int i=1;i<=n;i++){
        cin>>w[i];
    }
    memset(dis,0x3f,sizeof(dis));
    for(int i=1;i<=m;i++){
        cin>>k[i];
//        a[i].resize(k[i]+5);
//        t[i].resize(k[i]+5);
        for(int j=1;j<=k[i];j++){
            cin>>a[i][j]>>t[i][j];
//            dis[a[i][j]][a[i][j-1]]=0;
//            dis[a[i][j-1]][a[i][j]]=0;
        }
//        int a1,t1,a2,t2;
//        cin>>a1>>t1;
//        if(k<2)continue;
//        cin>>a2>>b2;
//        dis[a1][a2]=0;
//        dis[a2][a1]=0;
//        t[a1][i]=t1;
//        t[a2][i]=t2;
        //g[a1].push_back({,a2});
    }
    //cerr<<"Y"<<endl;
    int t=a[1][1];
    for(int i=1;i<=m;i++){
        for(int j=1;j<=k[i];j++){
            for(int q=1;q<=k[i];q++){
                    //cerr<<a[i][j]<<' '<<a[i][q]<<endl;
                if(j==q)continue;
                dis[a[i][j]][a[i][q]]=w[j]+t+t+w[q];
                dis[a[i][q]][a[i][j]]=w[j]+t+t+w[q];
            }
        }
    }
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                dis[i][j]=min(dis[i][j],dis[i][k]+w[i]+t+dis[k][j]+t+w[j]);
            }
        }
    }
    while(q--){
        int x,y;
        cin>>x>>y;
        cout<<dis[x][y]<<endl;
    }
    return 0;
}

