#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,n,m,d,q,a[500010],dis[510][510],k,sum=1e18,ans;
struct node{
    int x,v;
};
vector<node> e[510];
vector<node> p[500010];
bool cmp(node a,node b){
    return a.x<b.x;
}
int find(int i,int x){
    int l=0,r=e[i].size()-1;
    while(l<=r){
        int mid=l+r>>1;
        if(e[i][mid].x==x) return e[i][mid].v;
        if(e[i][mid].x<x) l=mid+1;
        else r=mid-1;
    }
    return -1;
}
void floyd(){
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            dis[i][i]=0;
            for(int j=1;j<=n;j++){
                if(i==j) continue;
                dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
            }
        }
    }
    return;
}
signed main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++) cin>>a[i];
    for(int i=1;i<=n;i++){
        cin>>k;
        int xx,vv;
        for(int j=1;j<=k;j++){
            cin>>xx>>vv;
            e[i].push_back({xx,vv});
            p[xx].push_back({i,vv});
        }
    }
    memset(dis,0x3f,sizeof(dis));
    for(int i=1;i<=n;i++) sort(e[i].begin(),e[i].end(),cmp);
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            for(auto jj:e[i]){
                int y=find(j,jj.x);
                if(y==-1) continue;
                dis[i][j]=min(dis[i][j],jj.v+y);
                dis[j][i]=dis[i][j];
            }
        }
    }
    floyd();
    for(int i=1;i<=q;i++){
        int x,y;
        cin>>x>>y;
        ans=1e18;
        for(auto ix:p[x]){
            for(auto iy:p[y]){
                ans=min(ans,dis[ix.x][iy.x]+ix.v+iy.v);
            }
        }
        ans+=a[x]+a[y];
        cout<<ans<<'\n';
    }
    return 0;
}
