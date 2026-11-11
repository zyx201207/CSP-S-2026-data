#include<bits/stdc++.h>
#define int long long
using namespace std;

inline int read(){
    int n=0,f=1;
    char c=getchar();
    while(c<'0'||'9'<c){
        if(c=='-')f=-1;
        c=getchar();
    }
    while('0'<=c&&c<='9'){
        n=(n<<3)+(n<<1)+(c^48);
        c=getchar();
    }
    return n*f;
}

inline void write(int x){
    if(x<0){
        x=-x;
        putchar('-');
    }
    if(x>9)write(x/10);
    putchar(x%10^48);
    return;
}

int n,m,q;
int w[500005];
vector<pair<int,int>>v[500005];
int g[505][505];
int dis[505][505];

void checkv(int f){
    int vf=v[f].size();
    for(int i=0;i<vf;++i){
        for(int j=0;j<i;++j){
            int x=v[f][i].first;
            int y=v[f][j].first;
            int t=v[f][i].second+v[f][j].second;
            g[x][y]=g[y][x]=t;
        }
    }
    return;
}

int check(int s,int t){
    int out=LLONG_MAX;
    int vs=v[s].size();
    int vt=v[t].size();
    for(int i=0;i<vs;++i){
        for(int j=0;j<vt;++j){
            int x=v[s][i].first;
            int y=v[t][j].first;
            int ti=v[s][i].second+v[t][j].second+dis[x][y];
            out=min(out,ti);
        }
    }
    return w[s]+out+w[t];
}

signed main(){
    freopen("subway.in","r",stdin);
    //freopen("subway3.in","r",stdin);
    freopen("subway.out","w",stdout);
    read();
    n=read();
    m=read();
    read();
    q=read();
    for(int i=1;i<=m;++i){
        w[i]=read();
    }
    for(int i=1;i<=n;++i){
        int k=read();
        for(int j=1;j<=k;++j){
            int a=read();
            int t=read();
            v[a].push_back({i,t});
        }
    }
    memset(g,0x3f,sizeof dis);
    for(int i=1;i<=m;++i){
        checkv(i);
    }
    for(int i=1;i<=n;++i)g[i][i]=0;
    memcpy(dis,g,sizeof dis);
    for(int k=1;k<=n;++k){
        for(int i=1;i<=n;++i){
            for(int j=1;j<=n;++j){
                dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
            }
        }
    }
    while(q--){
        int x=read();
        int y=read();
        write(check(x,y));putchar('\n');
    }
    return 0;
}