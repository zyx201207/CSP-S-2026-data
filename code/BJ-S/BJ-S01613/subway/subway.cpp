#include<bits/stdc++.h>

#define int long long

int c,n,m,d,q;

int a[500005];
int w[505][505];

std::vector<std::pair<int,int> > b[500005];

void adde(int u,int v,int z){
    w[u][v]=w[v][u]=std::min(w[u][v],z);
    return;
}

signed main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);

    std::ios::sync_with_stdio(false);
    std::cin.tie(0),std::cout.tie(0);

    std::cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++) std::cin>>a[i];
    memset(w,0x3f,sizeof(w));
    for(int i=1;i<=n;i++) w[i][i]=0;
    for(int i=1;i<=n;i++){
        int L; std::cin>>L;
        while(L--){
            int x,y; std::cin>>x>>y;
            for(std::pair<int,int> j:b[x]){
                adde(i,j.first,j.second+y);
            }
            b[x].push_back(std::make_pair(i,y));
        }
    }
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++) for(int j=1;j<=n;j++){
            w[i][j]=std::min(w[i][j],w[i][k]+w[k][j]);
        }
    }
    while(q--){
        int x,y; std::cin>>x>>y;
        int ans=0x3f3f3f3f3f3f3f3f;
        for(std::pair<int,int> p:b[x]){
            for(std::pair<int,int> p1:b[y]){
                ans=std::min(ans,w[p.first][p1.first]+p.second+p1.second);
            }
        }
        ans+=a[x]+a[y];
        std::cout<<ans<<'\n';
    }
    return 0;
}
