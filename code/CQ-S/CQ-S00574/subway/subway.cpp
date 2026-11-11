#include<bits/stdc++.h>
#define pii pair<long long,long long>
#define mp make_pair
#define inf 0x3f3f3f3f3f3f3f3f
using namespace std;
const long long N=1e6+50;
long long c,n,m,d,q;
long long w[N],k[N];
vector<long long> a[N],t[N];
vector<pii> sub[N];
long long G[505][505];
long long query(long long u,long long v){
    long long ret=inf;
    for(auto [au,tu]:sub[u]){
        for(auto [av,tv]:sub[v]){
            ret=min(ret,G[au][av]+tu+tv+w[u]+w[v]);
        }
    }
    return ret;
}
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++)cin>>w[i];
    for(int i=1;i<=n;i++){
        cin>>k[i];
        for(int j=1,A,T;j<=k[i];j++){
            cin>>A>>T;
            a[i].push_back(A);
            t[i].push_back(T);
            sub[A].push_back(mp(i,T));
        }
    }
    memset(G,0x3f,sizeof G);
    for(int i=1;i<=n;i++)G[i][i]=0;
    for(int i=1;i<=m;i++){
        for(int l=0;l<sub[i].size();l++){
            for(int r=l+1;r<sub[i].size();r++){
                G[sub[i][l].first][sub[i][r].first]=min(G[sub[i][l].first][sub[i][r].first],sub[i][l].second+sub[i][r].second);
                G[sub[i][r].first][sub[i][l].first]=min(G[sub[i][r].first][sub[i][l].first],sub[i][l].second+sub[i][r].second);
            }
        }
    }
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                G[i][j]=min(G[i][j],G[i][k]+G[k][j]);
            }
        }
    }
    for(int i=1,x,y;i<=q;i++){
        cin>>x>>y;
        cout<<query(x,y)<<'\n';
    }
    return 0;
}
/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2
*/
