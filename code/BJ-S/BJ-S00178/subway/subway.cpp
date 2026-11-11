#include <bits/stdc++.h>
#define rep(i,s,t) for(long long i=s;i<=t;i++)
using namespace std;
long long n,m,d,q,tmp;
long long dis[502][502];
long long tt5[25][500005];
long long tmpt[500005],srt[500005],siz[500005],sub[500005][25],ans[100005];
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    scanf("%lld%lld%lld%lld%lld",&tmp,&n,&m,&d,&q);
    for(int i=1;i<=m;i++){
        long long x;
        scanf("%lld",&x);
        srt[i]=x;
    }
    rep(i,1,n){
        cin>>tmp;
        rep(j,1,tmp){
            long long x,y;
            scanf("%lld%lld",&x,&y);
            sub[x][++siz[x]]=i;
            tt5[siz[x]][x]=y;
        }
    }
    rep(i,1,n){
        rep(j,1,n){
            if(i!=j)dis[i][j]=1e18;
        }
    }

    rep(j,1,m){
        rep(i,1,siz[j]){
            rep(k,1,siz[j]){
                long long x=sub[j][i],y=sub[j][k];
                dis[x][y]=dis[y][x]=tt5[i][j]+tt5[k][j];
            }
        }
    }
    rep(i,1,n){
        dis[i][i]=0;
    }
    rep(i,1,n){
        rep(j,1,n){
            rep(k,1,n){
                dis[j][k]=dis[k][j]=min(dis[j][k],dis[i][k]+dis[i][j]);
            }
        }
    }
    rep(ii,1,q){
        long long x,y;
        scanf("%lld%lld",&x,&y);
        ans[ii]=1e18;
        rep(i,1,siz[x]){
            rep(j,1,siz[y]){
                long long sx=sub[x][i],sy=sub[y][j];
                ans[ii]=min(ans[ii],dis[sx][sy]+tt5[i][x]+tt5[j][y]);
            }
        }
        ans[ii]=ans[ii]+srt[x]+srt[y];
        cout<<ans[ii]<<endl;
    }
    return 0;
}
