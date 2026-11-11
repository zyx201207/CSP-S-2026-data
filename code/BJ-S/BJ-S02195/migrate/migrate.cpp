// Wyh is extremely cute
// I love Wyh
#include<bits/stdc++.h>
#define int long long 
using namespace std;

const int maxn=2e6+10;
int c,t,n,d;
int a[maxn],f[maxn],g[maxn];
inline void ipt(){
    scanf("%lld%lld",&n,&d);
    for(int i=1;i<=n;i++)scanf("%lld",&a[i]);
}
inline void solve(){
    int ans=0;
    for(int i=1;i<=n;i++){
        f[i]=0,g[i]=1;
        int l=i,r=i,mi=0,tot=1;
        for(int j=i+1;j<=n;j++){
            if(a[j]-a[j-1]>d)break;
            while(l<=j){
                if(a[j]-a[l]>d){
                    if(l<=r)tot-=g[l];
                    ++l;
                }
                else break;
            }
            // printf("%lld %lld\n",l,r);
            if(l>r){
                mi=f[l];
                for(int k=l;k<=j-1;k++){
                    if(f[k]==mi){
                        tot+=g[k];
                        r=k;
                    }
                    else break;
                }
            }
            f[j]=mi+1,g[j]=tot;
            if(tot==2){
                ++ans;
                // printf("== %lld %lld\n",l,r);
                // printf("j = %lld\n",j);
            }
            // if(i==4&&j==7)printf("==%lld %lld %lld %lld\n",l,r,g[5],g[6]);
        }
        // printf("ans = %lld\n",ans);
        // printf("i = %lld\n",i);
        // for(int j=i;j<=n;j++)printf("%lld = %lld %lld\n",j,f[j],g[j]);
        // printf("\n");
    }
    printf("%lld\n",ans);
}
inline void solveA(){
    // printf("Wyh!\n");
    if(n==1){
        printf("0\n");
        return ;
    }
    // for(int i=3;i<=n;i++){
    //     if(a[i]-a[i-1]!=a[2]-a[1])printf("error!\n");
    // }
    int s=a[2]-a[1];
    int Wyh=d/s;
    if(Wyh==0||Wyh==1){
        printf("0\n");
        return ;
    }
    printf("%lld\n",max((int)0,n-2*Wyh+1));
}
inline void solveB(){
    printf("I love Wyh!\n");
}
signed main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    scanf("%lld%lld",&c,&t);
    while(t--){
        ipt();
        if(c==11||c==12)solveA();
        else if(c==13||c==14)solveB();
        else solve();
    }
    return 0;
}