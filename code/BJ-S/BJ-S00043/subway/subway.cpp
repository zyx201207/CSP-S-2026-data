#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int c,n,m,d,q;
long long dis[505][505],substation[500005];
struct node{
    int xl;
    long long st;
}a[500005][25];
int cnt[500005];
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin >> c >> n >> m >> d >> q;
    for(int i = 1;i <= m;i++){
        scanf("%lld",&substation[i]);
    }
    for(int i = 1,k;i <= n;i++){
        scanf("%d",&k);
        int u;
        long long t;
        for(int j = 1;j <= k;j++){
            scanf("%d%lld",&u,&t);
            cnt[u] ++;
            a[u][cnt[u]].xl = i;
            a[u][cnt[u]].st = t;
        }
    }
    memset(dis,0x3f3f3f3f3f3f3f3f,sizeof(dis));
    for(int i = 1;i <= m;i++){
        for(int j = 1;j <= cnt[i];j++){
            for(int l = j + 1;l <= cnt[i];l++){
                dis[a[i][j].xl][a[i][l].xl] = min(dis[a[i][j].xl][a[i][l].xl],a[i][j].st + a[i][l].st);
                dis[a[i][l].xl][a[i][j].xl] = min(dis[a[i][l].xl][a[i][j].xl],a[i][j].st + a[i][l].st);
            }
        }
    }
    for(int i = 1;i <= n;i++){
        dis[i][i] = 0;
    }
    for(int k = 1;k <= n;k++){
        for(int i = 1;i <= n;i++){
            for(int j = 1;j <= n;j++){
                dis[i][j] = min(dis[i][j],dis[i][k] + dis[k][j]);
            }
        }
    }
    while(q--){
        int start,finish;
        scanf("%d%d",&start,&finish);
        long long ans = 0x3f3f3f3f3f3f3f3f;
        for(int i = 1;i <= cnt[start];i++){
            for(int j = 1;j <= cnt[finish];j++){
                ans = min(ans,a[start][i].st + a[finish][j].st + dis[a[start][i].xl][a[finish][j].xl]);
            }
        }
        printf("%lld\n",ans + substation[start] + substation[finish]);
    }
    return 0;
}
