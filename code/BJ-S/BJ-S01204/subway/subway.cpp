#include<bits/stdc++.h>
using namespace std;
long long n,m,d,q,w[500005],a[500005][21][2],mp[505][505];
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    scanf("%lld%lld%lld%lld%lld",&n,&n,&m,&d,&q);
    for(int b=1;b<=m;b++)scanf("%lld",&w[b]);
    for(int b=1;b<=n;b++){
        for(int c=1;c<=n;c++)if(b!=c)mp[b][c]=1e15;
        long long k,x,y;
        scanf("%lld",&k);
        for(int c=1;c<=k;c++){
            scanf("%lld%lld",&x,&y);
            for(int e=1;e<=a[x][0][0];e++)mp[b][a[x][e][0]]=mp[a[x][e][0]][b]=min(mp[b][a[x][e][0]],y+a[x][e][1]);
            a[x][++a[x][0][0]][0]=b;
            a[x][a[x][0][0]][1]=y;
        }
    }
    for(int b=1;b<=n;b++)for(int c=1;c<=n;c++)for(int e=1;e<=n;e++)mp[c][e]=min(mp[c][e],mp[c][b]+mp[b][e]);
    for(int b=1;b<=q;b++){
        long long x,y,ans=1e15;
        scanf("%lld%lld",&x,&y);
        for(int c=1;c<=a[x][0][0];c++)for(int e=1;e<=a[y][0][0];e++)ans=min(ans,a[x][c][1]+a[y][e][1]+mp[a[x][c][0]][a[y][e][0]]);
        printf("%lld\n",ans+w[x]+w[y]);
    }
    return 0;
}