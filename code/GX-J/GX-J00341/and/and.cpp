#include<bits/stdc++.h>
using namespace std;
struct Node{
    long long num;
    bool b[33];
}a[214514];
int n,m,flat[214514],sum=0,f[214514],fsum=0;
long long pow2[33];
int powb[33];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    scanf("%d%d",&n,&m);
    pow2[0]=1;
    for(int i=1;i<=31;i++) pow2[i]=pow2[i-1]*2;
    for(int i=1;i<=n;i++)
        for(int j=0;j<=31;j++)
            a[i].b[j]=false;
    memset(powb,0,sizeof(powb));
    for(int i=1;i<=n;i++){
        scanf("%lld",&a[i].num);
        long long x=a[i].num;
        for(int j=31;j>=0 && x;j--){
            if(x>=pow2[j]){
                a[i].b[j]=true;
                powb[j]++;
                x-=pow2[j];
            }
        }
        flat[i]=i;
    }
    fsum=n;
    for(int i=31;i>=0;i--){
        if(powb[i]>=m){
            flat[++sum]=i;
            int qi[214514],fsum2=0;
            memset(powb,0,sizeof(powb));
            for(int j=1;j<=fsum;j++)
                if(a[j].b[i]){
                    qi[++fsum2]=j;
                    for(int k=i-1;k>=0;k--)
                        if(a[j].b[k])
                            powb[k]++;
                }
            if(fsum2>=m){
                fsum=fsum2;
                for(int j=1;j<=fsum2;j++) flat[j]=qi[j];
            }else{
                break;
            }
        }
    }
    long long ans=a[flat[1]].num;
    for(int j=2;j<=m;j++){
        ans&=a[flat[j]].num;
    }
    printf("%lld\n",ans);
    return 0;
}
