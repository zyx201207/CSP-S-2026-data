#include<bits/stdc++.h>
using namespace std;
int const N=200010;
struct da{
    long long p;
    char c;
};
da g[N],h1[N],h2[N];
long long n;
long long l;
long long ht1,ht2;
long long ans;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    scanf("%lld",&n);
    for(long long i=1;i<=n;i++){
        scanf("%lld %c",&g[i].p,&g[i].c);
        l+=g[i].p;
    }
    long long mid=1,mi;
    char mm=1;
    if(l%2==0){
        mid=l/2;
    }
    else{
        mid=l/2+1;
    }
    mi=mid;
    for(long long i=1;i<=n;i++){
        if(mi-g[i].p>0){
            mi-=g[i].p;
        }
        else{
            mm=g[i].c;
            for(long long j=i;j>=1;j--){
                ht1++;
                h1[ht1].c=g[j].c;
                if(j==i){
                    if(l%2==0){
                        h1[ht1].p=mi;
                    }
                    else{
                        h1[ht1].p=mi-1;
                    }
                }
                else{
                    h1[ht1].p=g[j].p;
                }
            }
            for(long long j=i;j<=n;j++){
                ht2++;
                h2[ht2].c=g[j].c;
                if(j==i){
                    h2[ht2].p=g[j].p-mi;
                }
                else{
                    h2[ht2].p=g[j].p;
                }
            }
            break;
        }
    }
    for(;ht1!=0&&ht2!=0;){
        long long d1=h1[ht1].p;
        long long d2=h2[ht2].p;
        char c1=h1[ht1].c,c2=h2[ht2].c;
        if(d1<d2){
            if(c1==c2){
                ht1--;
                h2[ht2].p-=d1;
            }
            else{
                ans+=d1;
                ht1--;
                h2[ht2].p-=d1;
            }
        }
        else if(d1>d2){
            if(c1==c2){
                ht2--;
                h1[ht1].p-=d2;
            }
            else{
                ans+=d2;
                ht2--;
                h1[ht1].p-=d2;
            }
        }
        else{
            if(c1==c2){
                ht2--;
                ht1--;
            }
            else{
                ans+=d2;
                ht2--;
                ht1--;
            }
        }
    }
    printf("%lld",ans);
    return 0;
}
