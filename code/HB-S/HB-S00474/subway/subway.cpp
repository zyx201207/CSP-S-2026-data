#include<bits/stdc++.h>
using namespace std;
const int M=5e5+50,N=550,D=25;
const long long INF=1e18;
long long c,n,m,d,q;
long long k[N];
long long e[M][D],t[M][D],tl[M];
long long w[M];
long long mp[N][N];
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    scanf("%lld%lld%lld%lld%lld",&c,&n,&m,&d,&q);
    for(long long i=1;i<=m;i++){
        scanf("%lld",&w[i]);
    }
    for(long long i=1;i<=n;i++){
        scanf("%lld",&k[i]);
        for(long long j=1;j<=k[i];j++){
            long long a,tm;
            scanf("%lld%lld",&a,&tm);
            e[a][tl[a]]=i;
            t[a][tl[a]]=tm;
            tl[a]++;
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(i==j) continue;
            mp[i][j]=INF;
        }
    }
    for(long long i=1;i<=m;i++){
        long long l=tl[i];
        for(long long p=0;p<l;p++){
            for(long long q=0;q<l;q++){
                if(p==q) continue;
                mp[e[i][p]][e[i][q]]=min(t[i][p]+t[i][q],mp[e[i][p]][e[i][q]]);
            }
        }
    }
    queue <pair<long long,long long>> qq;
    for(long long i=1;i<n;i++){
        for(long long j=i+1;j<=n;j++){
            if(mp[i][j]<INF) qq.push({i,j});
        }
    }
    while(!qq.empty()){
        long long x=qq.front().first,y=qq.front().second;
        qq.pop();
        for(long long i=1;i<=n;i++){
            if(i==x ||i==y) continue;
            if(mp[i][x]>mp[i][y]+mp[x][y]){
                mp[i][x]=mp[i][y]+mp[x][y];
                mp[x][i]=mp[i][y]+mp[x][y];
                qq.push({i,x});
            }
            if(mp[i][y]>mp[i][x]+mp[x][y]){
                mp[i][y]=mp[i][x]+mp[x][y];
                mp[y][i]=mp[i][x]+mp[x][y];
                qq.push({i,y});
            }
        }
    }
    while(q--){
        long long x,y;
        scanf("%lld%lld",&x,&y);
        long long cnt=INF;
        long long xl=tl[x],yl=tl[y];
        for(long long i=0;i<xl;i++){
            for(long long j=0;j<yl;j++){
                cnt=min(cnt,w[x]+w[y]+mp[e[x][i]][e[y][j]]+t[x][i]+t[y][j]);
            }
        }
        printf("%lld\n",cnt);
    }
    return 0;
}
