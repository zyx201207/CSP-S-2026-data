#include<bits/stdc++.h>
using namespace std;
const long long inf=0x3f3f3f3f3f3f3f3f;
long long c,n,m,d,q,f[1010][1010],w[500010],a[500010],t[500010],vis[500010],T[3][500010];
vector<pair<long long,long long> >g[500010];
priority_queue<pair<long long,long long> >que;
bitset<500010>bs[3];
long long read(){
    long long x=0;char ac=getchar();
    while(ac<'0' || ac>'9') ac=getchar();
    while(ac>='0' && ac<='9') x=x*10+ac-'0',ac=getchar();
    return x;
}
void dij(long long s){
    while(!que.empty()) que.pop();
    for(long long i=1;i<=m;i++)
        vis[i]=0;
    f[s][s]=0,que.push(make_pair(0,s));
    while(!que.empty()){
        long long now=que.top().second;
        que.pop();
        if(vis[now]) continue;
        vis[now]=1;
        for(auto v:g[now])
            if(f[s][v.first]>f[s][now]+v.second)
                f[s][v.first]=f[s][now]+v.second,que.push(make_pair(-f[s][v.first],v.first));
    }
    return ;
}
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    c=read(),n=read(),m=read(),d=read(),q=read();
    for(long long i=1;i<=m;i++)
        w[i]=read();
    if(c>=1 && c<=8){
        for(long long i=1;i<=m;i++)
            for(long long j=1;j<=m;j++)
                f[i][j]=inf;
        for(long long i=1;i<=n;i++){
            long long x=read();
            for(long long j=1;j<=x;j++)
                a[j]=read(),t[j]=read();
            for(long long j=1;j<=x;j++)
                for(long long k=1;k<=x;k++)
                    f[a[j]][a[k]]=f[a[k]][a[j]]=min(f[a[j]][a[k]],t[j]+t[k]);
        }
        for(long long k=1;k<=m;k++)
            for(long long i=1;i<=m;i++)
                for(long long j=1;j<=m;j++)
                    if(f[i][k]!=inf && f[k][j]!=inf)
                        f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
        // for(long long i=1;i<=m;i++){
        //     for(long long j=1;j<=m;j++)
        //         printf("%lld ",f[i][j]);
        //     printf("\n");
        // }
        while(q--){
            long long x=read(),y=read();
            // printf("%lld %lld %lld ",x,y,f[x][y]);
            printf("%lld\n",f[x][y]+w[x]+w[y]);
        }        
    }
    if(c>=9 && c<=11){
        for(long long i=1;i<=m;i++)
            for(long long j=1;j<=m;j++)
                f[i][j]=inf;
        for(long long i=1;i<=n;i++){
            long long x=read();
            for(long long j=1;j<=x;j++)
                a[j]=read(),t[j]=read();
            for(long long j=1;j<=x;j++)
                for(long long k=1;k<=x;k++)
                    f[a[j]][a[k]]=f[a[k]][a[j]]=min(f[a[j]][a[k]],t[j]+t[k]);
        }
        for(long long i=1;i<=m;i++)
            for(long long j=i+1;j<=m;j++)
                if(f[i][j]!=inf)
                    g[i].push_back(make_pair(j,f[i][j])),
                    g[j].push_back(make_pair(i,f[i][j]));
        for(long long i=1;i<=m;i++)
            for(long long j=1;j<=m;j++)
                f[i][j]=inf;
        for(long long i=1;i<=m;i++)
            dij(i);
        // for(long long i=1;i<=m;i++){
        //     for(long long j=1;j<=m;j++)
        //         printf("%lld ",f[i][j]);
        //     printf("\n");
        // }
        while(q--){
            long long x=read(),y=read();
            printf("%lld\n",f[x][y]+w[x]+w[y]);
        }
    }
    if(c==20 || c==21){
        for(long long i=1;i<=n;i++){
            long long x=read();
            for(long long j=1;j<=x;j++)
                a[j]=read(),t[j]=read(),bs[i][a[j]]=1,T[i][a[j]]=t[j];
        }
        bitset<500010> tmp=(bs[1]&bs[2]);
        long long s=inf;
        for(long long i=1;i<=m;i++)
            if(tmp[i]==1) s=min(s,T[1][i]+T[2][i]);
        while(q--){
            long long x=read(),y=read(),ans=inf;
            if(bs[1][x]==1 && bs[1][y]==1) ans=min(ans,T[1][x]+T[1][y]);
            if(bs[2][x]==1 && bs[2][y]==1) ans=min(ans,T[2][x]+T[2][y]);
            if(s!=inf)
                if(bs[1][x]==1 && bs[2][y]==1)
                    ans=min(ans,T[1][x]+T[2][y]+s);
                else ans=min(ans,T[1][y]+T[2][x]+s);
            printf("%lld\n",ans+w[x]+w[y]);
        }
    }
    return 0;
}