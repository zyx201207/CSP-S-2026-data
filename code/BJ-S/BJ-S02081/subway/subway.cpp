#include<bits/stdc++.h>
using namespace std;
#define LL long long
#define N 505
#define M 500005

inline LL read(){
    char ch=getchar();
    int w=1;
    LL p=0;
    while(ch<'0'||'9'<ch){
        if(ch=='-')w=-w;
        ch=getchar();
    }
    while('0'<=ch&&ch<='9'){
        p=(p<<3)+(p<<1)+(ch^48);
        ch=getchar();
    }
    return p*w;
}
inline void write(LL x){
    if(x<0)putchar('-'),x=-x;
    if(x>9)write(x/10);
    putchar('0'+x%10);
}
inline int readI(){
    char ch=getchar();
    int w=1;
    int p=0;
    while(ch<'0'||'9'<ch){
        if(ch=='-')w=-w;
        ch=getchar();
    }
    while('0'<=ch&&ch<='9'){
        p=(p<<3)+(p<<1)+(ch^48);
        ch=getchar();
    }
    return p*w;
}
inline void writeI(int x){
    if(x<0)putchar('-'),x=-x;
    if(x>9)write(x/10);
    putchar('0'+x%10);
}

LL dis[N][N];
int w[M];
vector<pair<int,int> >have[M];
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    int c=readI(),n=readI(),m=readI(),d=readI(),q=readI();
    for(int i=1;i<=m;i++)w[i]=readI();
    for(int i=1;i<=n;i++){
        int x=readI();
        for(int j=1;j<=x;j++){
            int y=readI(),z=readI();
            have[y].push_back({i,z});
        }
    }
    /*
    for(int i=1;i<=m;i++){
        printf("%lld: ",i);
        for(int j=0;j<have[i].size();j++){
            printf("{%lld,%lld},",have[i][j].first,have[i][j].second);
        }
        printf("\n");
    }
    */
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(i==j)dis[i][j]=0;
            else dis[i][j]=LLONG_MAX/10;
        }
    }
    for(int i=1;i<=m;i++){
        for(int j=0;j<have[i].size();j++){
            for(int k=j+1;k<have[i].size();k++){
                int u=have[i][j].first,v=have[i][k].first;
                dis[u][v]=dis[v][u]=min(dis[u][v],(LL)have[i][j].second+(LL)have[i][k].second);
             //   printf("u:%lld v:%lld |%lld\n",u,v,(LL)have[i][j].second+(LL)have[i][k].second);
            }
        }
    }
    /*
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            printf("%lld ",dis[i][j]);
        }
        printf("\n");
    }
    */
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                dis[i][j]=dis[j][i]=min(dis[i][j],dis[i][k]+dis[k][j]);
    }


    while(q--){
        int x=readI(),y=readI();
        LL ans=LLONG_MAX/10;
        for(int i=0;i<have[x].size();i++){
            for(int j=0;j<have[y].size();j++){
                int u=have[x][i].first,v=have[y][j].first;
                ans=min(ans,w[x]+w[y]+dis[u][v]+have[x][i].second+have[y][j].second);
            }
        }
        write(ans);
        putchar('\n');
    }
    return 0;
}
