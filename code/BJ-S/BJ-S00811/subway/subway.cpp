#include<bits/stdc++.h>
using namespace std;
#define int long long
int fw,a,b,c,t,d[1000005];
vector<pair<int,int> >ve[1000005];
int dis[505][505];
signed main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>fw>>a>>b>>c>>t;
    for(int i=1;i<=b;i++){
        cin>>d[i];
    }
    for(int i=1;i<=a;i++){
        int x;
        cin>>x;
        for(int j=1;j<=x;j++){
            int l,r;
            cin>>l>>r;
            ve[l].push_back({i,r});
        }
    }
    memset(dis,0x3f,sizeof(dis));
    for(int i=1;i<=a;i++){
        dis[i][i]=0;
    }
    for(int x=1;x<=b;x++){
        for(int i=0;i<ve[x].size();i++){
            for(int j=0;j<ve[x].size();j++){
                dis[ve[x][i].first][ve[x][j].first]=min(dis[ve[x][i].first][ve[x][j].first],ve[x][i].second+ve[x][j].second);
                dis[ve[x][j].first][ve[x][i].first]=min(dis[ve[x][j].first][ve[x][i].first],ve[x][i].second+ve[x][j].second);
            }
        }
    }
    for(int k=1;k<=a;k++){
        for(int i=1;i<=a;i++){
            for(int j=1;j<=a;j++){
                dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
            }
        }
    }
    while(t--){
        int l,r;
        cin>>l>>r;
        int re=1e18;
        for(int i=0;i<ve[l].size();i++){
            for(int j=0;j<ve[r].size();j++){
                re=min(re,ve[l][i].second+ve[r][j].second+dis[ve[l][i].first][ve[r][j].first]);
            }
        }
        cout<<d[l]+d[r]+re<<"\n";
    }
    return 0;
}
