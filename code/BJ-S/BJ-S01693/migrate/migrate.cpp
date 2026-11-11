#include<bits/stdc++.h>
using namespace std;
const int N=2e6+5;
int c,t;
int n;
#define ll long long
ll d;
ll x[N];
int f[N],g[N];
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    scanf("%d %d",&c,&t);
    while(t--){
        scanf("%d %lld",&n,&d);
        for(int i=1;i<=n;i++){
            scanf("%lld",&x[i]);
        }
        ll ans=0;
        for(int i=1;i<=n;i++){
            g[i]=1;
            f[i]=0;
            ll p=x[i]+d;
            int pos=upper_bound(x+1,x+1+n,p)-x-1;
            for(int j=i+1;j<=pos;j++){
                f[j]=1;
                g[j]=1;
            }
            for(int j=pos+1;j<=n;j++){
                int pos2=lower_bound(x+1,x+1+n,x[j]-d)-x;
                pos2=max(pos2,i);
                int pos3=upper_bound(f+pos2,f+j,f[pos2])-f-1;
                //printf("pos : %d %d %d\n",j,pos2,pos3);
                f[j]=f[pos2]+1;
                if(pos3-pos2+1>2){
                    g[j]=3;
                }
                else{
                    int cnt=0;
                    for(int k=pos2;k<=pos3;k++){
                        cnt+=g[k];
                    }
                    g[j]=cnt;
                }
                if(g[j]==2) ans++;
            }
            /*
            printf("%d\n",i);
            for(int j=i;j<=n;j++){
                printf("%d %d\n",f[j],g[j]);
            }
            */
        }
        printf("%lld\n",ans);
    }
}
/*

*/
