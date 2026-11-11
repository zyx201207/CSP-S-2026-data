#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e6;
int c,t,a[N];
signed main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    scanf("%lld %lld",&c,&t);
    while(t--){
        int n,d;
        bool flag=true;
        memset(a,0,sizeof a);
        if(n<=3){
            printf("0\n");
            continue;
        }
        for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
        for(int i=1;i<=n;i++){
            if(a[i]-a[i-1]!=a[i-2]-a[i-1]) flag=false;
        }
        if(flag){
            int cha=a[2]-a[1];
            int g=d/cha;
            if(g==0 || g==1) printf("0\n");
            else printf("%lld\n",g+3);
        }
    }
    return 0;
}
