#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10,M=505;
struct xinlu{
    int k;
    vector<pair<int,int>> g;
}xl[M];
struct EDGE{
    int to,next,w;
}edge[N<<3];
inline void add(int x,int y){
    edge[++cntt].to=y;
    edge[cntt].next=head[x];
    head[x]=cntt;
}
int cntt,head[N];
int jinru[10005];
int cnt[10005];
int point[N],tmp;
int dist[N][N];
int c,n,m,d,q;
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++)cin>>jinru[i];
    for(int i=1;i<=n;i++){
        int k;
        cin>>k;
        for(int j=1;j<=k;j++){
            int x,y;
            cin>>x>>y;
            xl[i].k=k;
            xl[i].g.push_back(make_pair(x,y));
            cnt[x]++;
            point[i]=++tmp;
        }
    }
    for(int i=1;i<n;i++){
        auto u=xl[i];
        for(auto p:u.g){
        }
    }
    for(int i=1;i<=q;i++){
        int x,y;
        cin>>x>>y;

    }
    return 0;
}