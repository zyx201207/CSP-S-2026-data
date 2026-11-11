#include<cstdio>
#include<iostream>
#include<cstring>
#include<vector>
#include<climits>
using namespace std;
long long f[510][510];
vector<pair<int,long long> > g[510000];
long long w[510000];
int n,m;
int d,q;
int Id;

int main() {
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    scanf("%d%d%d%d%d",&Id,&n,&m,&d,&q);
    for(int i=1;i<=m;i++) {
        scanf("%lld",&w[i]);
    }
    for(int i=1;i<=n;i++) {
        int k;
        scanf("%d",&k);
        for(int j=1;j<=k;j++) {
            int x;
            long long val;
            scanf("%d%lld",&x,&val);
            g[x].push_back({i,val});
        }
    }
    memset(f,0x3f,sizeof(f));
    for(int i=1;i<=m;i++) {
        // printf("%d : ",i);
        for(pair<int,long long> j:g[i]) {
            // printf("{%d,%lld}",j.first,j.second);
            for(pair<int,long long> k:g[i]) {
                f[j.first][k.first]=min(f[j.first][k.first],j.second+k.second);
            }
        }
        // printf("\n");
    }
    for(int i=1;i<=n;i++) f[i][i]=0;
    for(int k=1;k<=n;k++) {
        for(int i=1;i<=n;i++) {
            for(int j=1;j<=n;j++) {
                f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
            }
        }
    }
    // for(int i=1;i<=n;i++) {
    //     for(int j=1;j<=n;j++) {
    //         printf("%lld ",f[i][j]);
    //     }
    //     printf("\n");
    // }
    while(q--) {
        int x,y;
        scanf("%d%d",&x,&y);
        long long ans=LONG_LONG_MAX;
        for(pair<int,long long> i:g[x]) {
            for(pair<int,long long> j:g[y]) {
                // printf("$$  {%d,%lld}  {%d,%lld}\n",i.first,i.second,j.first,j.second);
                ans=min(ans,f[i.first][j.first]+i.second+j.second);
                // printf("$$  {%d,%lld}  {%d,%lld} %lld\n",i.first,i.second,j.first,j.second);
            }
        }
        ans+=w[x]+w[y];
        printf("%lld\n",ans);
    }
}
/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2

*/