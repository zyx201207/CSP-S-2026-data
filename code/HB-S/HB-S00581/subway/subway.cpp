#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;
int c,n,m,d,q,k,st,en,r,y,w[500086];
long long ans,ma[505][505];
struct edge{
    int to,v;
};
vector<edge> sta[500086];
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> c >> n >> m >> d >> q;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            ma[i][j]=1e18;
            if(i==j)ma[i][j]=0;
        }
    }
    for(int i=1;i<=m;i++)cin >> w[i];
    for(int i=1;i<=n;i++){
        cin >> k;
        for(int j=0;j<k;++j){
            cin >> r >> y;
            sta[r].push_back(edge{i,y});
        }
    }
    for(int i=1;i<=m;i++){
        for(edge e1:sta[i]){
            for(edge e2:sta[i]){
                ma[e1.to][e2.to]=ma[e2.to][e1.to]=min(ma[e1.to][e2.to],1ll*e1.v+e2.v);
            }
        }
    }
    for(int mi=1;mi<=n;++mi){
        for(int i=1;i<=n;++i){
            for(int j=1;j<=n;++j){
                if(i==j)continue;
                ma[i][j]=min(ma[i][j],1ll*ma[i][mi]+ma[mi][j]);    
            }
        }
    }
    while(q--){
        ans=1e18;
        cin >> st >> en;
        for(edge s:sta[st]){
            for(edge e:sta[en]){
                ans=min(ans,1ll*s.v+e.v+ma[s.to][e.to]);
            }
        }
        ans+=w[st]+w[en];
        if(st==en)ans=0;
        cout << ans << '\n';
    }
    return 0;
}