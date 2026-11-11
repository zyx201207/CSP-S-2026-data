#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>

using namespace std;

int x,y;
int vis[20010][20];//dian || xianlubianhao
int a[20010][510];// dian xianlubianhao changdu
int aio[20010];//churuzhanchangdu
int al[20010];//diandexianshu
long long dx[510][510];//xianjianchangdu min
long long c,n,m,d,q,ans;

int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    scanf("%lld%lld%lld%lld%lld",&c,&n,&m,&d,&q);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            dx[i][j]=(1e10)+1;
            if(i==j)dx[i][j]=0;
        }
    }
    for(int i=1;i<=m;i++){
        scanf("%d",&(aio[i]));
    }
    for(int i=1;i<=n;i++){
        scanf("%d",&y);
        for(int j=1;j<=y;j++){
            scanf("%d",&x);
            scanf("%d",&a[x][i]);
            vis[x][++al[x]]=i;
        }
    }
    for(int i=1;i<=m;i++){
        for(int j=1;j<=al[i];j++){
            for(int k=j+1;k<=al[i];k++){
                 if(dx[j][k]>a[i][vis[i][j]]+a[i][vis[i][k]]){
                    dx[k][j]=dx[j][k]=a[i][vis[i][j]]+a[i][vis[i][k]];
                 }
            }
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(i==j)continue;
            for(int k=1;k<=n;k++){
                if((i==k)||(j==k))continue;
                if(dx[i][j]>dx[i][k]+dx[k][j]){
                    dx[j][i]=dx[i][j]=dx[i][k]+dx[k][j];
                }
            }
        }
    }
    while(q--){
        ans=(1e10)+2;
        scanf("%d%d",&x,&y);
        for(int i=1;i<=al[x];i++){
            for(int j=1;j<=al[y];j++){
                if(ans>a[x][vis[x][i]]+a[y][vis[y][j]]+dx[vis[x][i]][vis[y][j]]){
                    ans=a[x][vis[x][i]]+a[y][vis[y][j]]+dx[vis[x][i]][vis[y][j]];
                }
            }
        }
        printf("%lld\n",(ans+aio[x]+aio[y])%(1000000000));
    }
    return 0;
}
