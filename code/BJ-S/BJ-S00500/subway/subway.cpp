#include <bits/stdc++.h>
using namespace std;
long long c,n,m,d,q,w[500005];
long long mp[1005][1005];
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    scanf("%lld %lld %lld %lld %lld",&c,&n,&m,&d,&q);
    for(int i=1;i<=m+n;i++){
        for(int j=1;j<=m+n;j++){
            mp[i][j]=1e10;
        }
    }
    for(int i=1;i<=m;i++){
        scanf("%lld",&w[i]);
    }
    for(int i=1;i<=n;i++){
        long long k;
        scanf("%lld",&k);
        for(int j=1;j<=k;j++){
            long long a,t;
            scanf("%lld %lld",&a,&t);
            mp[i+m][a]=mp[a][i+m]=t;
        }
    }

    for(int k=1;k<=m+n;k++){
        for(int i=1;i<=m+n;i++){
            if(mp[i][k]!=(long long)1e10 && i!=k){
                for(int j=1;j<=m+n;j++){
                    if(i!=j && j!=k && mp[k][j]!=(long long)1e10){
                        mp[i][j]=min(mp[i][k]+mp[k][j],mp[i][j]);
                    }
                }
            }
        }
    }
    for(int i=1;i<=q;i++){
        long long x,y;
        scanf("%lld %lld",&x,&y);
        long long ans=w[x]+w[y]+mp[x][y];
        printf("%lld\n",ans);
    }

    fclose(stdin);
    fclose(stdout);
    return 0;
}
