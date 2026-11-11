#include<bits/stdc++.h>
#define LL long long
#define Uint unsigned int
#define ULL unsigned LL
#define pii pair<int,int>
#define pLL pair<LL,LL>
#define fr first
#define se second
#define pb push_back
#define isr insert
#define _i128 __int128
using namespace std;
const int N = 505;
const int M = 5e5+5;
const LL INF = 1e18+1099;
int n,m,D,Q;
LL w[M],dis[N][N];//Floyd
vector<pLL> p[M];//(id,val)
LL read(){
    LL su=0,pp=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')pp=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){su=su*10+ch-'0';ch=getchar();}
    return su*pp;
}
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    read(),n=read(),m=read(),D=read(),Q=read();
    for(int i=1;i<=m;i++)w[i]=read();
    for(int i=1;i<=n;i++){
        int cnt=read();
        while(cnt--){
            int x=read();LL t=read();
            p[x].pb({i,t});
        }
    }
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            if(i!=j)dis[i][j]=INF;
            else dis[i][j]=0;
    for(int i=1;i<=m;i++){
        //从 i 这个站中转
        for(pLL x:p[i])for(pLL y:p[i]){
            if(x.fr==y.fr)continue;
            LL res=x.se+y.se;
            dis[x.fr][y.fr]=min(dis[x.fr][y.fr],res);
        }
    }
    for(int k=1;k<=n;k++)
        for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)
            dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
    while(Q--){
        int u=read(),v=read();
        LL ans=INF;
        for(pLL x:p[u])for(pLL y:p[v])
            ans=min(ans,x.se+y.se+dis[x.fr][y.fr]);
        cout<<ans+w[u]+w[v]<<"\n";
    }
    return 0;
}
//rp++
//为何你不接受我的爱 满怀心意爱你却要离开 ——《杀人兔》
