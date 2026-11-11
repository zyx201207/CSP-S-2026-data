#include<bits/stdc++.h>
using namespace std;
long long v[300005];
long long l[300005];
long long f[300005];
long long zv[300005];
long long a[500005];
long long n,m;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    scanf("%lld%lld",&n,&m);
    for(long long i=1;i<=n;i++){
        scanf("%lld",&a[i]);
    }
    for(long long j=1;j<=n;j++){
        for(long long i=j;i<=n;i++){
            if(v[a[i]]==0){
                v[a[i]]=i;
            }else{
                f[v[a[i]]]=1;
                v[a[i]]=-1;
                l[a[i]]=i;
            }
        }
        for(long long i=j;i<=n;i++){
            long long tem;
            if(l[a[i]]>0){
                tem=l[a[i]];
                l[a[i]]=0;
            }else{
                tem=300002;
            }
            f[tem]=-1;
            f[i]=f[i]+f[i-1];

            if(f[i]==0){
                zv[a[i]]++;
            }
        }
        for(long long i=1;i<=m;i++){
            v[i]=0;
            l[i]=0;
        }
        for(long long i=1;i<=n;i++){
            f[i]=0;
        }
    }
    for(long long i=1;i<=m;i++){
        printf("%lld ",zv[i]);
    }
    return 0;
}
