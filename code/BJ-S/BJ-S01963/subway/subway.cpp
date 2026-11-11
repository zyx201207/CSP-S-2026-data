#include <cctype>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
#define int long long
#define pb push_back
#define gc_u getchar_unlocked
#define pc_u putchar_unlocked
const int N=5e5+5,K=505,Inf=1e18;
int cid,n,m,d,q,cw[N],dis[K][K];
void read(int &res){
    res=0;
    char c=gc_u();
    while(!isdigit(c))c=gc_u();
    while(isdigit(c))res=(res<<1)+(res<<3)+c-48,c=gc_u();
}
void write(int res){
    if(!res){
        pc_u('0');pc_u('\n');
        return ;
    }
    int cnt=0,cc[20];
    while(res){
        cc[++cnt]=res%10;
        res/=10;
    }
    while(cnt)pc_u(cc[cnt--]+48);
    pc_u('\n');
}
struct Node{
    int u,d;
};
vector<Node>E[N];
signed main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    read(cid),read(m),read(n),read(d),read(q);
    for(int i=1;i<=n;i++)read(cw[i]);
    for(int i=1,t;i<=m;i++){
        read(t);
        for(int j=1,v,w;j<=t;j++){
            read(v),read(w);
            E[v].pb({i,w});
        }
    }
    for(int i=0;i<=m;i++){
        for(int j=0;j<=m;j++){
            dis[i][j]=Inf;
        }
        dis[i][i]=0;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<E[i].size();j++){
            auto [v1,w1]=E[i][j];
            for(int k=0;k<j;k++){
                auto [v2,w2]=E[i][k];
                dis[v1][v2]=dis[v2][v1]=min(dis[v1][v2],w1+w2);
            }
        }
    }
    for(int i=1;i<=m;i++){
        for(int j=1;j<=m;j++){
            for(int k=1;k<=m;k++){
                dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
            }
        }
    }
    for(int i=1,x,y;i<=q;i++){
        read(x),read(y);
        int ans=Inf;
        for(auto [j,w1]:E[x]){
            for(auto [k,w2]:E[y]){
                ans=min(ans,w1+w2+dis[j][k]);
            }
        }
        write(ans+cw[x]+cw[y]);
    }
}
