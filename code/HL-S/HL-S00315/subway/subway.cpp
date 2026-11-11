#include <bits/stdc++.h>
using namespace std;
using ll=long long;
int w[550000];
vector<pair<int,ll> > lines[550000];
ll dis[550][550];
int main(){
#ifndef HCX
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
#endif
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int c,n,m,d,q;
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++){
        cin>>w[i];
    }
    for(int i=1;i<=n;i++){
        int k;
        cin>>k;
        for(int j=1;j<=k;j++){
            int a,t;
            cin>>a>>t;
            lines[a].push_back({i,t});
        }
    }
    memset(dis,0x3f,sizeof dis);
    for(int i=1;i<=n;i++){
        dis[i][i]=0;
    }
    for(int i=1;i<=m;i++){
        for(int j=0;j<lines[i].size();j++){
            for(int k=j+1;k<lines[i].size();k++){
                dis[lines[i][j].first][lines[i][k].first]=min(dis[lines[i][j].first][lines[i][k].first],lines[i][j].second+lines[i][k].second);
                dis[lines[i][k].first][lines[i][j].first]=min(dis[lines[i][k].first][lines[i][j].first],lines[i][j].second+lines[i][k].second);
            }
        }
    }
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                dis[i][j]=min(dis[i][k]+dis[k][j],dis[i][j]);
            }
        }
    }
    for(int i=1;i<=q;i++){
        int x,y;
        cin>>x>>y;
        ll ans=w[x]+w[y],ans2=LLONG_MAX;
        for(int j=0;j<lines[x].size();j++){
            for(int k=0;k<lines[y].size();k++){
                int al=lines[x][j].first,ar=lines[y][k].first;
                ll lw=lines[x][j].second,rw=lines[y][k].second;
                ans2=min(ans2,lw+rw+dis[al][ar]);
            }
        }
        cout<<ans+ans2<<"\n";
    }
    return 0;
}
// build:
// g++ subway.cpp -o subway -O2 -Wall -Wextra -Wconversion -Wshadow
// debug:
// g++ subway.cpp -o subway -DHCX -g -fsanitize=address,undefined -Wall -Wextra -Wconversion -Wshadow