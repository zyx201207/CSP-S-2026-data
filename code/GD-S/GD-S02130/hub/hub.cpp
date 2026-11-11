#include<bits/stdc++.h>
using namespace std;
#define online
constexpr int maxn=1010;
vector<pair<int,int> >f;
int n,k;
int fa[maxn];
#define find _find
__inline int find(int x){
    if(fa[x]==x)return x;
    return fa[x]=find(fa[x]);
}
int dis[maxn][maxn];
int main(){
    #ifdef online
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    #endif
    ios::sync_with_stdio(false);cin.tie(0);
    int c,t;cin>>c>>t;
    while(t--){
        cin>>n>>k;
        f.clear();
        for(int i=1;i<n;i++){
            int u,v;cin>>u>>v;
            u--,v--;
            f.push_back(make_pair(u,v));
        }
        if(c<=3){
            memset(dis,0x3f,sizeof(dis));
            for(int i=0;i<n;i++)dis[i][i]=0;
            for(auto x:f)dis[x.first][x.second]=dis[x.second][x.first]=1;
            for(int i=0;i<n;i++)for(int j=0;j<n;j++)for(int k=0;k<n;k++)dis[j][k]=min(dis[j][k],dis[j][i]+dis[i][k]);
            int ans=1e9;
            for(int s=0;s<(1<<n);s++){
                if(__builtin_popcount(s)!=k)continue;
                for(int i=0;i<n;i++)fa[i]=i;
                for(auto x:f){
                    if((s>>x.first)&(s>>x.second)&1)fa[find(x.first)]=find(x.second);
                }
                int cnt=0;
                for(int p=0;p<n;p++){
                    if((s>>p)&1)cnt+=(p==find(p));
                }
                if(cnt>2)continue;
                // cerr<<s<<'\n';
                int p=0;
                for(int x=0;x<n;x++){
                    int tmp=1e9;
                    for(int y=0;y<n;y++)if((s>>y)&1)tmp=min(tmp,dis[x][y]);
                    p=max(p,tmp);
                }
                ans=min(ans,p);
            }
            cout<<ans<<'\n';
            continue;
        }
        if(c==7){
            memset(dis,0x3f,sizeof(dis));
            for(int i=0;i<n;i++)dis[i][i]=0;
            for(auto x:f)dis[x.first][x.second]=dis[x.second][x.first]=1;
            for(int i=0;i<n;i++)for(int j=0;j<n;j++)for(int k=0;k<n;k++)dis[j][k]=min(dis[j][k],dis[j][i]+dis[i][k]);
            int ans=1e9;
            for(int x=0;x<n;x++)for(int y=x+1;y<n;y++){
                int p=0;
                for(int r=0;r<n;r++)p=max(p,min(dis[x][r],dis[y][r]));
                ans=min(ans,p);
            }
            cout<<ans<<'\n';
            continue;
        }
    }
    return 0;
}