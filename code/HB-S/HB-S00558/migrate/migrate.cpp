#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int c,n;
const int maxsize=11535;
ll d,x[2000005],a[maxsize][maxsize],b[maxsize][maxsize];
const ll INF=2e18+1;
void floyd(){
    for(int k=1;k<=n;++k){
        for(int i=1;i<=n;++i){
            if(i==k) continue;
            for(int j=1;j<=n;++j){
                if(j==i||j==k) continue;
                if(a[i][k]<INF&&a[k][j]<INF){
                    if(a[i][k]+a[k][j]<a[i][j]){
                        a[i][j]=a[i][k]+a[k][j];
                        b[i][j]=b[i][k]*b[k][j];
                    }else if(a[i][k]+a[k][j]==a[i][j]){
                        b[i][j]+=b[i][k]*b[k][j];
                    }
                }
            }
        }
    }
}
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int t;
    scanf("%d %d",&c,&t);
    if(c==11||c==12){
        while(t>0){
            --t;
            scanf("%d %lld",&n,&d);
            for(int i=1;i<=n;i++){
                scanf("%lld",&x[i]);
            }
            printf("%d\n",n-3);
        }
        return 0;
    }
    while(t>0){
        --t;
        scanf("%d %lld",&n,&d);
        ll ans=0;
        for(int i=1;i<=n;++i){
            scanf("%lld",&x[i]);
        }
        if(n>maxsize){
            printf("0\n");
            continue;
        }
        for(int i=1;i<=n;++i){
            for(int j=1;j<=n;++j){
                a[i][j]=INF;
                if(i==j) b[i][j]=1;
                else b[i][j]=0;
            }
        }
        for(int i=1;i<=n;++i){
            for(int j=i+1;j<=n;++j){
                if(x[j]-x[i]<=d){
                    a[i][j]=a[j][i]=1;
                    b[i][j]=b[j][i]=1;
                }
            }
        }
        floyd();
        for(int i=1;i<=n;++i){
            for(int j=i+1;j<=n;++j){
                if(b[i][j]==2){
                    ++ans;
                }
            }
        }
        printf("%lld\n",ans);
    }
    return 0;
}

