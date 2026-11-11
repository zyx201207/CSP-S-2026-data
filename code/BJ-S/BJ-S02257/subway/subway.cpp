#include<bits/stdc++.h>
using namespace std;
#define int long long
inline int read(){
    int s=0,w=1;
    char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
    while(ch>='0'&&ch<='9')s=s*10+ch-'0',ch=getchar();
    return s*w;
}
const int N=505,M=5e5+5,INF=4e18;
int w[M],dist[N][N];
vector<pair<int,int>>a[M];
signed main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    read();int n=read(),m=read(),d=read(),q=read();
    for(int i=1;i<=m;i++)w[i]=read();
    for(int i=1;i<=n;i++){int k=read();
        for(int j=1;j<=k;j++){
            int v=read(),t=read();
            a[v].push_back({i,t});
        }
    }for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(i!=j)dist[i][j]=INF;
        }
    }for(int v=1;v<=m;v++){int sz=a[v].size();
        for(int i=0;i<sz;i++){
            for(int j=i+1;j<sz;j++){
                auto [x,tx]=a[v][i];auto [y,ty]=a[v][j];
                dist[x][y]=min(dist[x][y],tx+ty);
                dist[y][x]=min(dist[y][x],tx+ty);
            }
        }
    }for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            if(dist[i][k]==INF)continue;
            for(int j=1;j<=n;j++){
                if(dist[k][j]==INF)continue;
                dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]);
            }
        }
    }while(q--){
        int x=read(),y=read(),ans=INF;
        for(auto [i,ti]:a[x]){
            for(auto [j,tj]:a[y]){
                ans=min(ans,w[x]+ti+dist[i][j]+tj+w[y]);
            }
        }cout<<ans<<"\n";
    }
    return 0;
}

//g++ -std=c++14 -O2 B.cpp -o B