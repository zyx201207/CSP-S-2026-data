#include<bits/stdc++.h>
#define int long long
using namespace std;
int read(){
    int x=0,f=1;
    char ch=getchar();
    while(!isdigit(ch)){
        if(ch=='-')f=-1;
        ch=getchar();
    }
    while(isdigit(ch)){
        x=(x<<1)+(x<<3)+(ch^48);
        ch=getchar();
    }
    return x*f;
}
const int N=2e6+10;
const int M=3e2+10;
vector<int>edge[N];
int c,t,n,d,x[N];
int dis[M][M];
int cnt[M][M];
// queue<int>q;
void dfs(int u,int fa,int *dist,int *count){
    if(dist[u]>dist[fa]+1){dist[u]=dist[fa]+1;count[u]=1;}
    else if(dist[u]==dist[fa]+1){count[u]++;}
    for(auto i:edge[u])dfs(i,u,dist,count);
    return ;
}
// void bfs(int st,int *dist,int *cont){
//     for(int i=1;i<=n;i++){dist[i]=1e18;cont[i]=0;}
//     dist[st]=cont[st]=0;
//     q.push(st);
//     while(!q.empty()){
//         int front=q.front();
//         q.pop();
//         for(auto i:edge[front])
//             if(dist[i]>dist[front]+1){
//                 dist[i]=dist[front]+1;
//                 cont[i]=1;
//                 q.push(i);
//             }else if(dist[i]==dist[front]+1){
//                 cont[i]++;
//             }
//     }
//     return ;
// }
signed main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    c=read();t=read();
    if(c<=2){
        while(t--){
            n=read();d=read();
            for(int i=1;i<=n;i++)x[i]=read();
            for(int i=1;i<=n;i++)
            for(int j=i+1;j<=n;j++)
                if(x[j]<=d+x[i]||x[j]-d<=x[i])edge[i].push_back(j);
            for(int i=1;i<=n;i++){
                for(int j=1;j<=n;j++){dis[i][j]=1e18;}
                dfs(i,0,dis[i],cnt[i]);
            }
            int ans=0;
            // for(int i=1;i<=n;i++){
            //     for(int j=1;j<=n;j++)cerr<<cnt[i][j]<<" ";
            //     cerr<<"\n";
            // }
            // cerr<<"\n";
            // for(int i=1;i<=n;i++){
            //     for(int j=1;j<=n;j++)
            //         if(dis[i][j]==1e18)cerr<<"X ";
            //         else cerr<<dis[i][j]<<" ";
            //     cerr<<"\n";
            // }
            for(int i=1;i<=n;i++)
            for(int j=i+1;j<=n;j++)if(cnt[i][j]==2)ans++;
            printf("%lld\n",ans);
            for(int i=1;i<=n;i++)edge[i].clear();
        }
    }else if(c==11||c==12){
        while(t--){
            n=read();d=read();
            for(int i=1;i<=n;i++)x[i]=read();
            int c=x[2]-x[1];
            if(c>=d||x[1]+d>=x[n])printf("0\n");
            else printf("%lld\n",n-(2*(d/c)-1));
        }
    }
    return 0;
}
/*
-1000000000000000000 -10
-555555555555555558 -5
-111111111111111116 -1
 111111111111111105 1
 333333333333333326 3
 555555555555555547 5
 999999999999999989 9
 666666666666666663 6
*/
