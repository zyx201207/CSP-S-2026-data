#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define endl '\n'
#define w(x) cerr<<#x<<':'<<x<<endl
#define dbg cerr<<"\n----------------\n"
#define fi first
#define sc second
#define pii pair<int,int>
#define gc getchar_unlocked
#define pc putchar_unlocked
namespace IO{
    template<typename T>
    inline void read(T &x){
        x=0;char c=gc();bool fl=1;
        while(c<'0' || c>'9'){if(c=='-') fl=0;c=gc();}
        while(c>='0' && c<='9') x=(x<<1)+(x<<3)+c-48,c=gc();
        x=fl?x:-x;
    }
    template<typename T>
    void write(T x){
        if(x<0) x=-x,pc('-');
        if(x>9) write(x/10);
        pc('0'+x%10);
    }
    inline void read(char &c){while(isspace(c=gc()));}
    inline void write(char &c){pc(c);}
}using namespace IO;
const int inf=3e17;
const int mod=998244353;
const int M=5e2+5,N=5e5+5;
int T,d,n,m,x,y,z,q,k,l,r,c,L,cnt,now,sum,ans,len;
int dis[M][M],deg[N],w[N];
pii e[N][21];
signed main(){
//    ios::sync_with_stdio(0),cin.tie(),cout.tie();
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
//    cin>>c>>n>>m>>d>>q;
    read(c),read(n),read(m),read(d),read(q);
    for(int i=1;i<=m;i++){
//        cin>>w[i];
        read(w[i]);
    }

    for(int i=1;i<=n;i++){
        read(k);
//        cin>>k;
        for(int j=1;j<=k;j++){
//            cin>>x>>y;
            read(x),read(y);
            deg[x]++;
            e[x][deg[x]]={i,y};
        }
    }
    for(int i=1;i<=n;i++) for(int j=1;j<i;j++) dis[i][j]=dis[j][i]=inf;
    for(int i=1;i<=m;i++){
        for(int j=1;j<=deg[i];j++){
            for(int z=1;z<j;z++){
                int u=e[i][j].fi,v=e[i][z].fi,w=e[i][j].sc+e[i][z].sc;
                dis[u][v]=dis[v][u]=min(dis[v][u],w);
            }
        }
    }
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            if(dis[i][k]==inf) continue;
            for(int j=1;j<n;j++){
                if(dis[k][j]==inf) continue;
                dis[i][j]=dis[j][i]=min(dis[i][j],dis[i][k]+dis[k][j]);
            }
        }
    }
    for(int i=1;i<=q;i++){
//        cin>>x>>y;
        read(x),read(y);
        ans=inf;
        for(int j=1;j<=deg[x];j++){
            for(int k=1;k<=deg[y];k++){
                int u=e[x][j].fi,v=e[y][k].fi;
                ans=min(ans,dis[u][v]+e[x][j].sc+e[y][k].sc);
            }
        }
        ans+=w[x]+w[y];
        write(ans),pc('\n');
//        cout<<ans<<endl;
    }
    cerr<<endl<<1.0*clock()/CLOCKS_PER_SEC<<endl;
    return 0;
}
